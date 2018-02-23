
build: clean runtime

clean:
	rm components/*.component || echo 'already clean'

runtime:
	rm -rf build/tests
	mkdir -p build/tests
	./node_modules/.bin/microflo generate --components ./node_modules/microflo-core/components --target linux graphs/tests.fbp build/tests/runtime.cpp
	$(CXX) -std=c++0x -o build/tests/runtime build/tests/runtime.cpp -I./node_modules/microflo/microflo -lutil -lrt
