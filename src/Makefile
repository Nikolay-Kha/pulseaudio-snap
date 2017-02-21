CC          = gcc
CFLAGS      = -O2 -c -Wall
LDFLAGS     = -lpulse -lpulse-simple -lm
OBJDIR      = build
SOURCES     = main.c
OBJECTS     = $(addprefix $(OBJDIR)/, $(SOURCES:%.c=%.o))
EXECUTABLE  = csnap

.PHONY: all clean rebuild

all: $(SOURCES) $(EXECUTABLE)

clean:
	@rm -rf $(OBJDIR)

rebuild: clean all

$(EXECUTABLE): $(OBJECTS)
	@echo "LD $@" 
	@$(CC) $(OBJECTS) $(LDFLAGS) -o $@

$(OBJDIR)/%.o: %.c
	@echo "CC $<"
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

install: $(EXECUTABLE)
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	@cp $(EXECUTABLE) $(DESTDIR)$(PREFIX)/bin/

