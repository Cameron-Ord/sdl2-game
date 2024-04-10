clang -o game src/game.c src/errors.c src/audio_callback.c src/inputs.c src/sdl_init.c src/render.c src/textures.c src/player.c src/memory.c src/window.c -Isrc/inc -lSDL2 -lm -lsndfile -lSDL2_image
