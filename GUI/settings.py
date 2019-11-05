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

Builder.load_file('settings.kv')
possible_lang = sorted(["Pirate", "English", "Spanish", "French"])

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

    def updateDropdown(self, to_replace, replacement):
        #Looping through each button to find the correct one to update
        for button in self.languages.children[0].children:
            if button.text == to_replace:
                button.text = replacement

    def changeLanguage(self, language):
        old_lang = self.config["DISPLAY"]["language"]
        self.config.set('DISPLAY', 'language', language)

        self.updateDropdown(language, old_lang)
        self.mainbutton.text = old_lang
        
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

        navBar = NavigationBar()
        slide = Slider(min=-100, max=100, value=25)
        returnBtn = Button(text = "Return to Home")
        returnBtn.bind(on_press=self.returnHome)

        possible_lang.remove(self.config["DISPLAY"]["language"])
        self.languages = self.buildDropdown(possible_lang)

        self.mainbutton = Button(text=self.config["DISPLAY"]["language"], size_hint=(None, None))
        self.mainbutton.bind(on_release=self.languages.open)
        self.languages.bind(on_select=lambda instance, x: setattr(self.mainbutton, 'text', x))

        navBar.add_widget(returnBtn)
        navBar.add_widget(self.mainbutton)

        setting_layout.add_widget(slide)
        setting_layout.add_widget(navBar)
        self.add_widget(setting_layout)
