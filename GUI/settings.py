# Settings Tab of ALPACA
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
from kivy.uix.popup import Popup
from kivy.uix.label import Label

from kivy.base import runTouchApp
from kivy.graphics import Rectangle, Color

from kivy.lang import Builder
import configparser
import json

from Navigation import NavigationBar
from Navigation import NavigationButton

Builder.load_file('settings.kv')
possible_lang = sorted(["Pirate", "English", "Spanish", "French"])

#  Main settings Class
class SettingsScreen(Screen):
    # Function that returns user to the home page when the approriate button is pressed
    def returnHome(self, instance):
        self.manager.transition.direction = 'left'
        self.manager.current = 'Menu'

    # Function that builds the dropdown menu for languages
    def buildDropdown(self, langs):
        languages = DropDown()
        for index in range(len(langs)):
            btn = Button(text = langs[index], size_hint_y=None, height=22)
            btn.bind(on_release=lambda btn: self.languages.select(btn.text))
            btn.bind(on_press=lambda btn: self.changeLanguage(btn.text))
            languages.add_widget(btn)
        return languages

    # Function that changes language temporarily by changing config
    def changeLanguage(self, language):
        old_lang = self.config["DISPLAY"]["language"]

        if old_lang != language:
            self.config.set('DISPLAY', 'language', language)

            popup_content = BoxLayout()
            change_lan_yes = Button(text='Yes', size=(100,100))
            change_lan_no = Button(text='No', size=(100,100))
            popup_content.add_widget(change_lan_yes)
            popup_content.add_widget(change_lan_no)

            popup = Popup(title='Do you wish to set this language as the default?',
                        content=popup_content,
                        size_hint=(None, None), size=(500, 500))
            change_lan_no.bind(on_press=popup.dismiss)
            print(popup)
            change_lan_yes.bind(on_press=self.changeLanguagePerm)
            change_lan_yes.bind(on_release=popup.dismiss)
            popup.open()

    # Function that permently changes the language by comminting all changes to config file
    def changeLanguagePerm(self, instance):
        with open('../config.ini', 'w') as configfile:
            self.config.write(configfile)

    # Main function that builds the Settings page
    def __init__(self, config, **kwargs):
        self.config = config
        super(SettingsScreen, self).__init__(**kwargs)

        # Creates the main layout
        setting_layout = StackLayout()

        # Adds the high level widgets
        self.navBar = NavigationBar()
        slide = Slider(min=-100, max=100, value=25)
        returnBtn = NavigationButton(name="Return", text = "Return to Home")
        returnBtn.bind(on_press=self.returnHome)

         # Creates the language dropdown menu and associated buttons
        self.languages = self.buildDropdown(possible_lang)

        self.mainbutton = Button(text=self.config["DISPLAY"]["language"], size_hint=(0.1, 1))
        self.mainbutton.bind(on_release=self.languages.open)
        self.languages.bind(on_select=lambda instance, x: setattr(self.mainbutton, 'text', x))

        # Adds all widgets to layout
        self.navBar.add_widget(returnBtn)
        self.navBar.add_widget(self.mainbutton)

        setting_layout.add_widget(slide)
        setting_layout.add_widget(self.navBar)
        self.add_widget(setting_layout)

    # Function that is called before the usuer is switched to settings screen
    def on_pre_enter(self):
        self.updateScreenLanguage(self.config["DISPLAY"]["language"])

    # Function that updates the on screen language right before the user switches
    def updateScreenLanguage(self, language):
        navStrings = json.load( open("LangStrings.json") )
        langNavStrings = navStrings[language]["navButton"]

        for button in self.navBar.children:
            if isinstance(button, NavigationButton) and button.name in langNavStrings.keys():
                button.text = langNavStrings[button.name]
