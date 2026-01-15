CC := gcc
PROJNAME := LearningC
PROJDIRS := utils
SRCFILES := $(wildcard utils/*.c)
#$(info ${SRCFILES})
OBJFILES := $(SRCFILES:%.c=%.o)
#$(info ${OBJFILES})
DEPFILES := $(SRCFILES:%.c=%.d)
#$(info ${DEPFILES})

WARNINGS := -g -Wall -Wextra 
CFLAGS:= -std=c99 -MMD -MP $(WARNINGS)

all : $(OBJFILES)

#$(OBJFILES): $(SRCFILES)
#	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean
clean:
	find . -name "*.o" -type f -delete
	find . -name "*.s" -type f -delete
	find . -name "*.i" -type f -delete

-include $(DEPFILES)
