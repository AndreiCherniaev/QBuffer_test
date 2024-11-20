## About
Qt example how to use QBuffer.
## Compiling
```
git clone https://github.com/AndreiCherniaev/QBuffer_test.git && cd QBuffer_test
mkdir build/
cmake -S src/ -B build/ --fresh # qt-cmake -S src/ -B build/ -DCMAKE_BUILD_TYPE=Release --fresh
cmake --build build/ --parallel
```
## Run
Before start open source code and uncomment A) and comment B) and rebuild
### A) Open-close way
```
buf.close();
buf.open(QBuffer::WriteOnly);
```
Log
```
myflush;size;1;B;isNull;false
myflush;size;1;B;isNull;false
~;size;1;B;isNull;false
```
## B) Clear way
Then open source code and comment A) and uncomment B) and rebuild
```
buf.buffer().clear();
```
Log
```
myflush;size;1;B;isNull;false
myflush;size;2;B;isNull;false
~;size;2;B;isNull;false
```
