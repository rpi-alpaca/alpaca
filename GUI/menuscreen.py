from kivy.uix.screenmanager import Screen
from kivy.uix.button import Button
from kivy.graphics import Rectangle, Color
from kivy.uix.image import Image

from kivy.uix.boxlayout import BoxLayout
from kivy.uix.floatlayout import FloatLayout
from kivy.uix.stacklayout import StackLayout

from kivy.lang import Builder

import json

from Navigation import NavigationBar
from Navigation import NavigationButton

Builder.load_file('alpaca.kv')

class LogoBody(BoxLayout):
    pass

class AlpacaLogo(Image):
    pass

class HelpButton(Button):
    pass

# Main class for the main menu to build on top of
class MenuScreen(Screen):
    def __init__(self, config, **kwargs):
        self.config = config
        super().__init__(**kwargs)

        layout = StackLayout()
        body = LogoBody()
        self.navBar = NavigationBar()
    
        logo = AlpacaLogo()

        # Defining our buttons and binding them to their respective transitions
        helpBtn = HelpButton()
        helpBtn.bind(on_release=self.toHelp)

        textStrings = json.load( open("LangStrings.json") )
        englishStrings = textStrings[self.config["DISPLAY"]["language"]]
        navText = englishStrings["navButton"]

        settingsBtn = NavigationButton(name="Settings", text=navText["Settings"])
        settingsBtn.bind(on_release=self.toSettings)

        newProjectBtn = NavigationButton(name="NewProj", text=navText["NewProj"])
        newProjectBtn.bind(on_release=self.toNewProject)

        existingProjectBtn = NavigationButton(name="ExistProj", text=navText["ExistProj"])
        existingProjectBtn.bind(on_release=self.toExistingProject)
        
        # Add help button to body
        body.add_widget(logo)
        body.add_widget(helpBtn)

        # Add navigation buttons to navigation bar
        self.navBar.add_widget(settingsBtn)
        self.navBar.add_widget(newProjectBtn)
        self.navBar.add_widget(existingProjectBtn)

        # Finally, add all elements to the screen
        layout.add_widget(body)
        layout.add_widget(self.navBar)
        self.add_widget(layout)

    def on_pre_enter(self):
        self.updateScreenLanguage(self.config["DISPLAY"]["language"])
        
    def updateScreenLanguage(self, language):
        navStrings = json.load( open("LangStrings.json") )
        langNavStrings = navStrings[language]["navButton"]

		# Getting the buttons contained in navbar, and then looping 
        # through them to update their text
        for button in self.navBar.children:
            button.text = langNavStrings[button.name]
            

    def toHelp(self, instance):
        self.manager.transition.direction = 'down'
        self.manager.current = 'Help'

    def toSettings(self, instance):
        self.manager.transition.direction = 'right'
        self.manager.current = 'Settings'

    def toNewProject(self, instance):
        self.manager.transition.direction = 'up'
        self.manager.current = 'NewProject'

    def toExistingProject(self, instance):
        self.manager.transition.direction = 'left'
        self.manager.current = 'ExistingProject'