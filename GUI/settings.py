from kivy.uix.tabbedpanel import TabbedPanel
from kivy.uix.tabbedpanel import TabbedPanelItem
from kivy.uix.tabbedpanel import TabbedPanelHeader

from kivy.uix.floatlayout import FloatLayout
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.stacklayout import StackLayout

from kivy.uix.screenmanager import Screen
from kivy.uix.button import Button
from kivy.uix.slider import Slider
from kivy.uix.dropdown import DropDown
from kivy.uix.button import Button

from kivy.base import runTouchApp
from kivy.graphics import Rectangle, Color

from kivy.lang import Builder
import configparser

Builder.load_file('settings.kv')

class NavigationBar(BoxLayout):
    pass

# class SettingsHeader(TabbedPanelHeader):
#     def __init__(self, **kwargs):
#         super(TabbedPanelHeader, self).__init__(**kwars)
#         self.background_color = []


class SettingsScreen(Screen):
    def returnHome(self, instance):
        self.manager.transition.direction = 'left'
        self.manager.current = 'Menu'

    def PirateModeOn(self, instance):
        config = configparser.ConfigParser()
        config.read('../config.ini')
        config.set('DISPLAY', 'language', 'Pirate')

        with open('../config.ini', 'w') as configfile:
            config.write(configfile)

    def PirateModeOff(self, instance):
        config = configparser.ConfigParser()
        config.read('../config.ini')
        config.set('DISPLAY', 'language', 'English')
        with open('../config.ini', 'w') as configfile:
            config.write(configfile)

    def __init__(self, **kwargs):

        super(SettingsScreen, self).__init__(**kwargs)

        setting_layout = StackLayout()

        navBar = NavigationBar()
        slide = Slider(min=-100, max=100, value=25)
        returnBtn = Button(text = "Return to Home")
        changePirate = Button(text = "Turn on PirateMode")
        changePirateOff = Button(text = "Turn off PirateMode")

        returnBtn.bind(on_press=self.returnHome)
        changePirate.bind(on_press=self.PirateModeOn)
        changePirateOff.bind(on_press=self.PirateModeOff)

        navBar.add_widget(returnBtn)
        navBar.add_widget(changePirate)
        navBar.add_widget(changePirateOff)

        setting_layout.add_widget(slide)
        # setting_layout.add_widget(mainbutton)
        setting_layout.add_widget(navBar)
        self.add_widget(setting_layout)
