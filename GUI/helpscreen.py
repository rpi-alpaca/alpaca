from kivy.uix.tabbedpanel import TabbedPanel
from kivy.uix.tabbedpanel import TabbedPanelItem
from kivy.uix.tabbedpanel import TabbedPanelHeader
from kivy.uix.stacklayout import StackLayout
from kivy.uix.screenmanager import Screen
from kivy.uix.button import Button

class HelpPanelsHeader(TabbedPanelHeader):
  def __init__(self, **kwargs):
    super(TabbedPanelHeader, self).__init__(**kwargs)
    self.background_color = [0,1,1,1]

class HelpPanels(TabbedPanel):
  def __init__(self, **kwargs):
    super(HelpPanels, self).__init__(**kwargs)

# Main class for the help menu to build on top of
class HelpScreen(Screen):
  def __init__(self, **kwargs):
    super(HelpScreen, self).__init__(**kwargs)

    panels = HelpPanels()
    header = HelpPanelsHeader()