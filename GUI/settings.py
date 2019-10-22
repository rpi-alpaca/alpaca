from kivy.uix.tabbedpanel import TabbedPanel
from kivy.uix.tabbedpanel import TabbedPanelItem
from kivy.uix.tabbedpanel import TabbedPanelHeader

from kivy.uix.floatlayout import FloatLayout
from kivy.uix.boxlayout import BoxLayout
from kivy.uix.stacklayout import StackLayout

from kivy.uix.screenmanager import Screen
from kivy.uix.button import Button
from kivy.uix.slider import Slider
from kivy.graphics import Rectangle, Color

from kivy.lang import Builder

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

    def __init__(self, **kwargs):

        super(SettingsScreen, self).__init__(**kwargs)

        setting_layout = StackLayout()
        navBar = NavigationBar()
        slide = Slider(min=-100, max=100, value=25)
        returnBtn = Button(text = "Return to Home")
        returnBtn.bind(on_press=self.returnHome)
        navBar.add_widget(returnBtn)

        setting_layout.add_widget(slide)
        setting_layout.add_widget(navBar)
        self.add_widget(setting_layout)
