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
Before start open source code and uncomment A) and comment B),C) and rebuild
### A) Open-close way
```
buf.close();
buf.open(QBuffer::WriteOnly);
```
Log
```
Writer;size;1;1;B;isNull;false;buf_cnt;1
myflush;size;1;1;B;isNull;false
myflush;size;1;1;B;isNull;false
Writer;size;1;1;B;isNull;false;buf_cnt;1
~;size;1;1;B;isNull;false;buf_cnt;1
```
## B) Clear way
Then open source code and comment A),C) and uncomment B) and rebuild
```
buf.buffer().clear();
```
Log
```
Writer;size;1;1;B;isNull;false;buf_cnt;1
myflush;size;1;1;B;isNull;false
myflush;size;0;0;B;isNull;true
Writer;size;2;2;B;isNull;false;buf_cnt;1
~;size;2;2;B;isNull;false;buf_cnt;1
```
## C) Seek way
Then open source code and comment A),B) and uncomment C) and rebuild
```
buf.seek(0L);
```
Log
```
Writer;size;1;1;B;isNull;false;buf_cnt;1
myflush;size;1;1;B;isNull;false
myflush;size;1;1;B;isNull;false
Writer;size;1;1;B;isNull;false;buf_cnt;1
~;size;1;1;B;isNull;false;buf_cnt;1
```
