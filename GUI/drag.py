from kivy.uix.scatter import Scatter
from kivy.uix.button import Button
from kivy.uix.floatlayout import FloatLayout
from kivy.app import App
from kivy.uix.scatterlayout import ScatterLayout
from kivy.graphics.transformation import Matrix


class MyScatterLayout(ScatterLayout):
    move_lock = False
    scale_lock_left = False
    scale_lock_right = False
    scale_lock_top = False
    scale_lock_bottom = False
    def on_touch_up(self, touch):
        self.move_lock = False
        self.scale_lock_left = False
        self.scale_lock_right = False
        self.scale_lock_top = False
        self.scale_lock_bottom = False
        if touch.grab_current is self:
            touch.ungrab(self)
            x = self.pos[0] / 10
            x = round(x, 0)
            x = x * 10
            y = self.pos[1] / 10
            y = round(y, 0)
            y = y * 10
            self.pos = x, y
            return super(MyScatterLayout, self).on_touch_up(touch)

    def on_touch_down(self, touch):
        x, y = touch.x, touch.y
        self.prev_x = touch.x
        self.prev_y = touch.y
        # if the touch isnt on the widget we do nothing
        if not self.do_collide_after_children:
            if not self.collide_point(x, y):
                return False

        # let the child widgets handle the event if they want
        touch.push()
        touch.apply_transform_2d(self.to_local)
        if super(Scatter, self).on_touch_down(touch):
            # ensure children don't have to do it themselves
            if 'multitouch_sim' in touch.profile:
                touch.multitouch_sim = True
            touch.pop()
            self._bring_to_front(touch)
            return True
        touch.pop()

        # if our child didn't do anything, and if we don't have any active
        # interaction control, then don't accept the touch.
        if not self.do_translation_x and \
                not self.do_translation_y and \
                not self.do_rotation and \
                not self.do_scale:
            return False

        if self.do_collide_after_children:
            if not self.collide_point(x, y):
                return False

        if 'multitouch_sim' in touch.profile:
            touch.multitouch_sim = True
        # grab the touch so we get all it later move events for sure
        self._bring_to_front(touch)
        touch.grab(self)
        self._touches.append(touch)
        self._last_touch_pos[touch] = touch.pos

        return True

class MyButton(Button):
    def on_touch_down(self, touch):
        return False


class MyFloatLayout(FloatLayout):
    pass


class ScatterApp(App):
    def build(self):
        f = MyFloatLayout()
        s = MyScatterLayout(do_rotation=False, size=(150, 100), size_hint=(None, None), pos=(10, 10))
        s.add_widget(MyButton(id='mybutton', text='Test Button'))
        f.add_widget(s)
        s2 = MyScatterLayout(do_rotation=False, size=(150, 100), size_hint=(None, None), pos=(10, 120))
        s2.add_widget(MyButton())
        f.add_widget(s2)
        s3 = MyScatterLayout(do_rotation=False, size=(150, 100), size_hint=(None, None), pos=(10, 230))
        s3.add_widget(MyButton())
        f.add_widget(s3)

        return f


ScatterApp().run()
