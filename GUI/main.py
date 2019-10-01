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

class HelpScreen(Screen):

	pass

class NewProjectScreen(Screen):
        def createNew(self):
                self.submit = Button(text="Test", font_size = 40, size_hint = (0.25, 0.2))
                self.submit.bind(on_release=self.createNew)
                self.add_widget(self.submit)
                return

class ExistingProjectScreen(Screen):
    pass

class MenuScreen(Screen):
	pass

# Loading Multiple .kv files
Builder.load_file('alpaca.kv')
Builder.load_file('existingproject.kv')
Builder.load_file('helpscreen.kv')
Builder.load_file('newproject.kv')

class AlpacaApp(App):
    def build(self):
        # Create the screen manager
        sm = ScreenManager()
        sm.add_widget(MenuScreen(name='Menu'))
        sm.add_widget(HelpScreen(name='Help'))
        sm.add_widget(NewProjectScreen(name='NewProject'))
        sm.add_widget(ExistingProjectScreen(name='ExistingProject'))
        sm.current = 'NewProject'
        return sm

if __name__ == "__main__":
	Config.set('input', 'mouse', 'mouse,multitouch_on_demand')
	AlpacaApp().run()
