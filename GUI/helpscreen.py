from kivy.uix.tabbedpanel import TabbedPanelHeader
from kivy.uix.tabbedpanel import TabbedPanelItem
from kivy.uix.tabbedpanel import TabbedPanel

from kivy.uix.floatlayout import FloatLayout
from kivy.uix.stacklayout import StackLayout
from kivy.uix.boxlayout import BoxLayout

from kivy.graphics import Rectangle, Color
from kivy.uix.screenmanager import Screen
from kivy.uix.button import Button
from kivy.uix.label import Label

from kivy.lang import Builder

import configparser
import json

Builder.load_file('helpscreen.kv')

class HelpPanelsHeader(TabbedPanelHeader):
	pass

class HelpPanels(TabbedPanel):
	pass

class NavigationBar(BoxLayout):
	pass

def createInfoTab(stringDict, tabName):
	tab = TabbedPanelItem()
	tab.text = stringDict[tabName]["Title"]

	titleText = Label(text=stringDict[tabName]["Title"])
	bodyText = Label(text=stringDict[tabName]["Body"])
	
	tab.add_widget(titleText)
	tab.add_widget(bodyText)

	return tab

def createHelpPanels(pirate):
	infoPanels = HelpPanels()

	if pirate == True:
		language = "Pirate"
	else:
		language = "English"

	helpStrings = json.load( open("HelpStrings.json") )

	tabsToAdd = []
	tabsToAdd.append( createInfoTab(helpStrings[language], "What") )
	tabsToAdd.append( createInfoTab(helpStrings[language], "How")  ) 
	tabsToAdd.append( createInfoTab(helpStrings[language], "Who")  )

	for tab in tabsToAdd:
		infoPanels.add_widget(tab)

	return infoPanels

# Main class for the help menu to build on top of
class HelpScreen(Screen):
	def __init__(self, **kwargs):
		super().__init__(**kwargs)
		config = configparser.ConfigParser()
		config.read("../config.ini")

		layout = StackLayout()

		infoPanels = createHelpPanels(config["DISPLAY"]["lightmode"])

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
		
    
