FROM node:14-buster

RUN npm install

WORKDIR /app
COPY ./client-side .

CMD node webpage.js
