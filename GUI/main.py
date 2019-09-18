# this is the python file
# Gitpod test commit!
<<<<<<< HEAD
=======

# This file is the main code for the GUI for ALPACA. It acts as
#	the viewer in the MVC structure, and it allows interaction
#	with the logic engine

from kivy.app import App
from kivy.uix.widget import Widget
from kivy.graphics import *
from kivy.uix.image import Image

class AlpacaLogo(Image):
	pass

class Alpaca(Widget):
	pass

class AlpacaApp(App):
	def build(self):
		return Alpaca()

if __name__ == "__main__":
	AlpacaApp().run()
>>>>>>> GUI

