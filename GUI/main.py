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
from kivy.uix.scatterlayout import ScatterLayout

class HelpScreen(Screen):
	pass

class BlockNewProjectScreen(Screen): # gui screen
#	def __init__(self):
#		pass

#	def on_touch_down(self):
#		pass

    def createNew(self):
        self.submit = Button(text="Test", font_size = 40, size_hint = (0.25, 0.2))
        self.add_widget(self.submit)
        return

class TextNewProjectScreen(Screen): # text base screen
    pass
'''
class aButton(Button):
	def on_touch_down(self, touch):
		return False

'''
class ExistingProjectScreen(Screen):
    pass

class MenuScreen(Screen):
	pass

# Loading Multiple .kv files
Builder.load_file('alpaca.kv')
Builder.load_file('existingproject.kv')
Builder.load_file('helpscreen.kv')
Builder.load_file('blocknewproject.kv')
Builder.load_file('textnewproject.kv')

class AlpacaApp(App):
	def build(self):
        # Create the screen manager
		sm = ScreenManager()
		sm.add_widget(MenuScreen(name='Menu'))
		sm.add_widget(HelpScreen(name='Help'))
		sm.add_widget(BlockNewProjectScreen(name='BlockNewProject'))
		sm.add_widget(TextNewProjectScreen(name='TextNewProject'))
		sm.add_widget(ExistingProjectScreen(name='ExistingProject'))
		sm.current = 'BlockNewProject'
		return sm

if __name__ == "__main__":
	Config.set('input', 'mouse', 'mouse,multitouch_on_demand')
	AlpacaApp().run()
