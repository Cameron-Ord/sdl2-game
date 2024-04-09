clang -o game src/game.c src/errors.c src/audio_callback.c src/inputs.c src/sdl_init.c src/render.c src/textures.c -Isrc/inc -lSDL2 -lm -lsndfile
