#!/usr/bin/node

const request = require('request');
const url = 'https://swapi-api.hbtn.io/api/films/' + process.argv[2];

request(url, async function (error, response, body) {
  if (error) throw error;
  const characters = JSON.parse(body).characters;

  for (const characterId of characters) {
    await new Promise((resolve) => {
      request(characterId, function (error, response, body) {
        if (error) {
          throw error;
        }
        console.log(JSON.parse(body).name);
        resolve();
      });
    });
  }
});
