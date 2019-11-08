from kivy.uix.boxlayout import BoxLayout
from kivy.uix.button import Button

from kivy.uix.boxlayout import BoxLayout
from kivy.uix.button import Button
from kivy.lang import Builder

Builder.load_file('Navigation.kv')

class NavigationBar(BoxLayout):
  pass

class NavigationButton(Button):
  def __init__(self, name, text, **kwargs):
    super().__init__()
    self.name = name
    self.text = text