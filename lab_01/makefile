CC := gcc

FLAGS := -std=c99 -Wall -Werror -pedantic -Wextra -Wvla -Wfloat-conversion -Wfloat-equal -I ./inc/ -lm

OBJS_APP := $(patsubst ./src/%.c,./out/%.o,$(wildcard ./src/*.c))

.PHONY: release debug clean

.NOTPARALLEL: release debug clean

release: ./out/lastrelease | app.exe

debug: FLAGS += -g3
debug: ./out/lastdebug | app.exe

./out/:
	mkdir out

./out/lastrelease: ./out/
	touch ./out/lastrelease
	-rm app.exe
	-rm ./out/lastdebug

./out/lastdebug: ./out/
	touch ./out/lastdebug
	-rm app.exe
	-rm ./out/lastrelease

app.exe: ./out/ | $(OBJS_APP)
	$(CC) $(OBJS_APP) -o $@ -lm

./out/%.o: ./src/%.c ./inc/*.h
	$(CC) $(FLAGS) -c $< -o $@

./out/%.o: ./unit_tests/%.c ./inc/*.h
	$(CC) $(FLAGS) -c $< -o $@

clean:
	-rm -r out
	-rm app.exe
