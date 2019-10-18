from kivy.uix.tabbedpanel import TabbedPanel
from kivy.uix.tabbedpanel import TabbedPanelItem
from kivy.uix.tabbedpanel import TabbedPanelHeader

from kivy.uix.floatlayout import FloatLayout
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.stacklayout import StackLayout

from kivy.uix.screenmanager import Screen
from kivy.uix.button import Button
from kivy.graphics import Rectangle, Color

from kivy.lang import Builder
from kivy.properties import ObjectProperty

Builder.load_file('helpscreen.kv')

class HelpPanelsHeader(TabbedPanelHeader):
	pass

class HelpPanels(TabbedPanel):
	pass

class NavigationBar(BoxLayout):
	pass

# Main class for the help menu to build on top of
class HelpScreen(Screen):
	def __init__(self, **kwargs):
		super().__init__(**kwargs)

		layout = StackLayout()
		infoPanels = HelpPanels()

		navBar = NavigationBar()
		returnButton = Button(text="Return to home")
		returnButton.bind(on_press=self.returnHome)
		navBar.add_widget(returnButton)

		layout.add_widget(infoPanels)
		layout.add_widget(navBar)
		self.add_widget(layout)

	def returnHome(self, instance):
		self.manager.transition.direction = 'up'
		self.manager.current = 'Menu'
		
    
