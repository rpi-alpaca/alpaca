# This file is the main code for the GUI for ALPACA. It acts as
#	the viewer in the MVC structure, and it allows interaction
#	with the logic engine
from sys import exit
from kivy.app import App
from kivy.lang import Builder
from kivy.uix.widget import Widget
from kivy.graphics import *
from kivy.uix.image import Image
from kivy.uix.screenmanager import ScreenManager, Screen
from kivy.config import Config
from kivy.uix.button import Button
from kivy.uix.tabbedpanel import TabbedPanel
from kivy.uix.scatterlayout import ScatterLayout
from kivy.uix.screenmanager import ScreenManager, Screen, WipeTransition
from kivy.core.window import Window

# Screens defined in separate screen .py files
from helpscreen import HelpScreen
from settings import SettingsScreen
from menuscreen import MenuScreen

import configparser

class BlockNewProjectScreen(Screen): # gui screen

    def createNew(self):
        self.submit = Button(text="Test", font_size = 40, size_hint = (0.25, 0.2))
        self.add_widget(self.submit)
        return

class TextNewProjectScreen(Screen): # text base screen

	def parse(self, string):
		print(string)
'''
class aButton(Button):
	def on_touch_down(self, touch):
		return False

'''
class ExistingProjectScreen(Screen):
    pass

class DecideProjectScreen(Screen):
        pass

class MenuScreen(Screen):
	pass

# Loading Multiple .kv files
Builder.load_file('existingproject.kv')
Builder.load_file('helpscreen.kv')
Builder.load_file('blocknewproject.kv')
Builder.load_file('textnewproject.kv')
Builder.load_file('newprojectdecide.kv')

class AlpacaApp(App):
	def build(self):
        # Create the screen manager
		sm = ScreenManager()
		sm.add_widget(MenuScreen(name='Menu'))
		sm.add_widget(HelpScreen(name='Help'))
		sm.add_widget(BlockNewProjectScreen(name='BlockNewProject'))
		sm.add_widget(TextNewProjectScreen(name='TextNewProject'))
		sm.add_widget(ExistingProjectScreen(name='ExistingProject'))
		sm.add_widget(DecideProjectScreen(name='ProjectDecide'))
		sm.current = 'ProjectDecide'
		return sm
Builder.load_file('newproject.kv')

class AlpacaApp(App):
    def build(self):
        # Gather the config file options
        self.config = configparser.ConfigParser()
        self.config.read('../config.ini')

        # Create the screen manager
        sm = ScreenManager()
        sm.add_widget(MenuScreen(config=self.config, name='Menu'))
        sm.add_widget(HelpScreen(config=self.config, name='Help'))
        sm.add_widget(SettingsScreen(config=self.config, name='Settings'))
        sm.add_widget(NewProjectScreen(name='NewProject'))
        sm.add_widget(ExistingProjectScreen(name='ExistingProject'))
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
