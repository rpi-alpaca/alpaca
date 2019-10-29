# This file is the main code for the GUI for ALPACA. It acts as
#	the viewer in the MVC structure, and it allows interaction
#	with the logic engine
from sys import exit
from kivy.app import App
from kivy.lang import Builder
from kivy.uix.tabbedpanel import TabbedPanel
from kivy.uix.button import Button
from kivy.uix.widget import Widget
from kivy.graphics import *
from kivy.uix.image import Image
from kivy.uix.screenmanager import ScreenManager, Screen, WipeTransition
from kivy.core.window import Window

# Screens defined in separate screen .py files
from helpscreen import HelpScreen
from settings import SettingsScreen
from menuscreen import MenuScreen

import configparser

class NewProjectScreen(Screen):
	pass

class ExistingProjectScreen(Screen):
    pass

# Loading Multiple .kv files
Builder.load_file('existingproject.kv')
Builder.load_file('newproject.kv')

class AlpacaApp(App):
    def build(self):
        # Create the screen manager
        sm = ScreenManager()
        self.menuScreen = MenuScreen(name='Menu')
        self.helpScreen = HelpScreen(name='Help')
        self.settingsScreen = SettingsScreen(name='Settings')
        self.newProjectScreen = NewProjectScreen(name='NewProject')
        self.existingProjectScreen = ExistingProjectScreen(name='ExistingProject')

        sm.add_widget(self.menuScreen)
        sm.add_widget(self.helpScreen)
        sm.add_widget(self.settingsScreen)
        sm.add_widget(self.newProjectScreen)
        sm.add_widget(self.existingProjectScreen)
        sm.current = 'Menu'
        return sm

if __name__ == "__main__":
	config = configparser.ConfigParser()
	config.read('../config.ini')
	default = config['DEFAULT']

    # Apply default settings to the root window before execution
	Window.size = ( int(default['WindowSize_width']), int(default['WindowSize_height']) )
	Window.minimum_width = default['Window_Minimum_width']
	Window.minimum_height = default['Window_Minimum_height']

	AlpacaApp().run()
