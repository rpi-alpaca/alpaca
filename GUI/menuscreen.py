from kivy.uix.screenmanager import Screen
from kivy.uix.button import Button
from kivy.graphics import Rectangle, Color
from kivy.uix.image import Image

from kivy.uix.boxlayout import BoxLayout
from kivy.uix.floatlayout import FloatLayout
from kivy.uix.stacklayout import StackLayout

from kivy.lang import Builder

Builder.load_file('alpaca.kv')

class LogoBody(BoxLayout):
    pass

class AlpacaLogo(Image):
    pass

class HelpButton(Button):
    pass

class NavigationButton(Button):
    pass

class NavigationBar(BoxLayout):
    pass   

# Main class for the main menu to build on top of
class MenuScreen(Screen):
    def __init__(self, config, **kwargs):
        self.config = config
        super().__init__(**kwargs)

        layout = StackLayout()
        body = LogoBody()
        navBar = NavigationBar()
    
        logo = AlpacaLogo()

        # Defining our buttons and binding them to their respective transitions
        helpBtn = HelpButton()
        helpBtn.bind(on_release=self.toHelp)

        settingsBtn = NavigationButton(text="Settings")
        settingsBtn.bind(on_release=self.toSettings)

        newProjectBtn = NavigationButton(text="New Project")
        newProjectBtn.bind(on_release=self.toNewProject)

        existingProjectBtn = NavigationButton(text="Exisiting Project")
        existingProjectBtn.bind(on_release=self.toExistingProject)
        
        # Add help button to body
        body.add_widget(logo)
        body.add_widget(helpBtn)

        # Add navigation buttons to navigation bar
        navBar.add_widget(settingsBtn)
        navBar.add_widget(newProjectBtn)
        navBar.add_widget(existingProjectBtn)

        # Finally, add all elements to the screen
        layout.add_widget(body)
        layout.add_widget(navBar)
        self.add_widget(layout)

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