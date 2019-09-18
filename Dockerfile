FROM gitpod/workspace-full-vnc

# Install dependencies
RUN apt-get update \
    && apt-get install -y libgtk-3-dev \
    && apt-get clean && rm -rf /var/cache/apt/* && rm -rf /var/lib/apt/lists/* && rm -rf /tmp/* \
    && python -m pip install --upgrade pip wheel setuptools virtualenv \
    && python -m pip install docutils pygments pypiwin32 kivy_deps.sdl2==0.1.22 kivy_deps.glew==0.1.12 \
    && python -m pip install kivy_deps.gstreamer==0.1.17 \
    && python -m pip install kivy_deps.angle==0.1.9 \
    && python -m pip install kivy==1.11.1
