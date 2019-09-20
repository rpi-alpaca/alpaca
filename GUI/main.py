# This file is the main code for the GUI for ALPACA. It acts as
#	the viewer in the MVC structure, and it allows interaction
#	with the logic engine

from sys import exit
from kivy.app import App
from kivy.lang import Builder
from kivy.uix.button import Button
from kivy.uix.widget import Widget
from kivy.graphics import *
from kivy.uix.image import Image
from kivy.uix.screenmanager import ScreenManager, Screen

# Create both screens. Please note the root.manager.current: this is how
# you can control the ScreenManager from kv. Each screen has by default a
# property manager that gives you the instance of the ScreenManager used.
Builder.load_string("""
<MenuScreen>:
    FloatLayout:
        BoxLayout:
            Button:
                text: 'Goto help'
                on_press: 
                    root.manager.transition.direction = 'up'
                    root.manager.current = 'Help'			
            Button:
                text: 'Goto new project'
                on_press: 
                    root.manager.transition.direction = 'up'
                    root.manager.current = 'NewProject'	
            Button:
                text: 'Goto existing project'
                on_press: 
                    root.manager.transition.direction = 'up'
                    root.manager.current = 'ExistingProject'

<HelpScreen>:
    FloatLayout:
        BoxLayout:
            Label:
                text: "Help screen"
            Button:
                text: 'Back to menu'
                on_press: 
                    root.manager.transition.direction = 'down'
                    root.manager.current = 'Menu'

<NewProjectScreen>:
    FloatLayout:
        BoxLayout:
            Label:
                text: "New project screen"
            Button:
                text: 'Back to menu'
                on_press: 
                    root.manager.transition.direction = 'down'
                    root.manager.current = 'Menu'

<ExistingProjectScreen>:
    FloatLayout:
        BoxLayout:
            Label:
                text: "Existing project screen"
            Button:
                text: 'Back to menu'
                on_press: 
                    root.manager.transition.direction = 'down'
                    root.manager.current = 'Menu'
""")

class HelpScreen(Screen):
	pass

class NewProjectScreen(Screen):
	pass

class ExistingProjectScreen(Screen):
    pass

class MenuScreen(Screen):
	pass

# Create the screen manager
sm = ScreenManager()
sm.add_widget(MenuScreen(name='Menu'))
sm.add_widget(HelpScreen(name='Help'))
sm.add_widget(NewProjectScreen(name='NewProject'))
sm.add_widget(ExistingProjectScreen(name='ExistingProject'))
sm.current = 'Menu'

class AlpacaApp(App):
	def build(self):
		return sm

if __name__ == "__main__":
	AlpacaApp().run()

