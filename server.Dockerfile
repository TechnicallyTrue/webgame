FROM python:3.8

RUN apt-get update \
  && apt-get install -y build-essential gcc g++ \
  && apt-get install -y swig \
  && apt-get clean 

WORKDIR /app
COPY ./server-side .

RUN pip install flask && pip install flask_cors
RUN python-config --cflags
RUN swig -c++ -python game.i
RUN g++ -c -fpic game_wrap.cxx game.cpp player.cpp state.cpp -I/usr/local/include/python3.8
RUN g++ -shared game.o player.o state.o game_wrap.o -o _game.so

CMD python3 server.py
