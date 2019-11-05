from kivy.uix.tabbedpanel import TabbedPanel
from kivy.uix.tabbedpanel import TabbedPanelItem
from kivy.uix.tabbedpanel import TabbedPanelHeader

from kivy.uix.floatlayout import FloatLayout
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.stacklayout import StackLayout

from kivy.uix.screenmanager import Screen
from kivy.uix.button import Button
from kivy.uix.slider import Slider
from kivy.uix.dropdown import DropDown
from kivy.uix.button import Button

from kivy.base import runTouchApp
from kivy.graphics import Rectangle, Color

from kivy.lang import Builder
import configparser
import json

Builder.load_file('settings.kv')
possible_lang = sorted(["Pirate", "English", "Spanish", "French"])

class NavigationButton(Button):
    def __init__(self, name, **kwargs):
        super().__init__()
        self.name = name

class NavigationBar(BoxLayout):
    pass

class SettingsScreen(Screen):
    def returnHome(self, instance):
        self.manager.transition.direction = 'left'
        self.manager.current = 'Menu'

    def buildDropdown(self, langs):
        languages = DropDown()
        for index in range(len(langs)):
            btn = Button(text = langs[index], size_hint_y=None, height=22)
            btn.bind(on_release=lambda btn: self.languages.select(btn.text))
            btn.bind(on_press=lambda btn: self.changeLanguage(btn.text))
            languages.add_widget(btn)
        return languages

    def changeLanguage(self, language):
        old_lang = self.config["DISPLAY"]["language"]
        self.config.set('DISPLAY', 'language', language)
        
        # Code to add later: allows choosing if default gets updated
        # choice = input(f"Would you like to save {language} as your default language? (y/n)")
        # if choice.lower() == "y":
        #     with open('../config.ini', 'w') as configfile:
        #         self.config.write(configfile)
        # else:
        #     print("Default not changed!")

    def __init__(self, config, **kwargs):
        self.config = config
        super(SettingsScreen, self).__init__(**kwargs)

        setting_layout = StackLayout()

        self.navBar = NavigationBar()
        slide = Slider(min=-100, max=100, value=25)
        returnBtn = NavigationButton(name="Return", text = "Return to Home")
        returnBtn.bind(on_press=self.returnHome)

        self.languages = self.buildDropdown(possible_lang)

        self.mainbutton = Button(text=self.config["DISPLAY"]["language"], size_hint=(None, None))
        self.mainbutton.bind(on_release=self.languages.open)
        self.languages.bind(on_select=lambda instance, x: setattr(self.mainbutton, 'text', x))

        self.navBar.add_widget(returnBtn)
        self.navBar.add_widget(self.mainbutton)

        setting_layout.add_widget(slide)
        setting_layout.add_widget(self.navBar)
        self.add_widget(setting_layout)

    def on_pre_enter(self):
        self.updateScreenLanguage(self.config["DISPLAY"]["language"])

    def updateScreenLanguage(self, language):
        navStrings = json.load( open("LangStrings.json") )
        langNavStrings = navStrings[language]["navButton"]

        for button in self.navBar.children:
            if isinstance(button, NavigationButton) and button.name in langNavStrings.keys():
                button.text = langNavStrings[button.name]
