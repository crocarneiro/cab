CFGLAGS := -std=c99 -Wall -pedantic
LIBS := -lm -lcurl

all: display.o requests.o app.o cJSON.o cJSON_Utils.o main.o
	gcc cJSON.o cJSON_Utils.o display.o requests.o app.o main.o -o cab $(LIBS)
main.o:
	gcc -c src/main.c -o main.o $(CFGLAGS)
app.o:
	gcc -c src/app.c -o app.o $(CFGLAGS)
requests.o:
	gcc -c src/requests.c -o requests.o $(CFGLAGS)
display.o:
	gcc -c src/display.c -o display.o $(CFGLAGS)
cJSON.o:
	gcc -c src/cJSON/cJSON.c $(CFGLAGS)
cJSON_Utils.o:
	gcc -c src/cJSON/cJSON_Utils.c $(CFGLAGS)
clean:
	- rm -f *.o
	- rm cab.exe