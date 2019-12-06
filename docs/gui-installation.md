# Installing Kivy

## Preqs
1. Python 3.7
2. pip (optional)

## Installation
1. Ensure you are up to date with everything:
          python -m pip install --upgrade pip wheel setuptools virtualenv

2. Create the environment in your current directory. In this case we will call it kivy_venv
          python -m virtualenv kivy_venv

3. Activate the virtual environment. NOTE you have to do this every time you start a new terminal
          kivy_venv\Scripts\activate
   If you are in a bash terminal:
          source kivy_venv/Scripts/activate

4. install the dependencies  
          python -m pip install docutils pygments pypiwin32 kivy_deps.sdl2==0.1.* kivy_deps.glew==0.1.*
          python -m pip install kivy_deps.gstreamer==0.1.*
  For Python 3.5+, you can also use the angle backend instead of glew
          python -m pip install kivy_deps.angle==0.1.*

5. Install kivy
          python -m pip install kivy==1.11.1
