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
possible_lang = ["Pirate", "English", "Spanish", "French"]

class NavigationBar(BoxLayout):
    pass



class SettingsScreen(Screen):
    def returnHome(self, instance):
        self.manager.transition.direction = 'left'
        self.manager.current = 'Menu'

    def changeLanguage(self, language):
        print(language)
        config = configparser.ConfigParser()
        config.read('../config.ini')
        config.set('DISPLAY', 'language', language)

        with open('../config.ini', 'w') as configfile:
            config.write(configfile)


    def __init__(self, **kwargs):

        super(SettingsScreen, self).__init__(**kwargs)

        setting_layout = StackLayout()

        navBar = NavigationBar()
        slide = Slider(min=-100, max=100, value=25)
        returnBtn = Button(text = "Return to Home")
        returnBtn.bind(on_press=self.returnHome)


        languages = DropDown()
        for index in range(len(possible_lang)):
            btn = Button(text = possible_lang[index], size_hint_y=None, height=22)
            btn.bind(on_release=lambda btn: languages.select(btn.text))
            btn.bind(on_press=lambda btn: self.changeLanguage(btn.text))
            languages.add_widget(btn)
        mainbutton = Button(text='Hello', size_hint=(None, None))
        mainbutton.bind(on_release=languages.open)
        languages.bind(on_select=lambda instance, x: setattr(mainbutton, 'text', x))

        navBar.add_widget(returnBtn)
        navBar.add_widget(mainbutton)

        setting_layout.add_widget(slide)
        setting_layout.add_widget(navBar)
        self.add_widget(setting_layout)
