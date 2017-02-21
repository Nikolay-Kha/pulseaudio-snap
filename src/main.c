#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <pulse/simple.h>
#include <pulse/error.h>


int main(int argc, char *argv[]) {
	int error;
	pa_simple *s;
	pa_sample_spec ss;
	ss.format = PA_SAMPLE_S16NE;
	ss.channels = 1;
	ss.rate = 16000;
	s = pa_simple_new(NULL, "Foo", PA_STREAM_PLAYBACK, NULL, "Test", &ss, NULL, NULL, &error);
	if(!s) {	
		fprintf(stderr, __FILE__": pa_simple_new() failed: %s\n", pa_strerror(error));
		return 1;
	}

	// generate signal
	short buf[8000];
	for(int i = 0; i < sizeof(buf)/sizeof(short); i++)
		buf[i] = 10000 * sin(i/2.0);

	// play in endless loop
	while(1) {
		if (pa_simple_write(s, buf, sizeof(buf), &error) < 0) {
			fprintf(stderr, __FILE__": pa_simple_write() failed: %s\n", pa_strerror(error));
			break;
		}
		usleep(5000000);
	}

	pa_simple_free(s);
	return 0;
}
