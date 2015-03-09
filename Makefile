#------------------------------
# Configurations
#------------------------------
ENV = Windows

TARGET = libavr8.a
TARGETDIR = ./lib

INCDIR = ./include
ifneq ($(INCDIR),)
  INCLUDES = -I $(INCDIR)
endif

SRCDIR = ./src
SRCSUFFIX = %.c

OBJDIR = ./obj
OBJSUFFIX = %.o

DEPSUFFIX = %.d

#------------------------------
# Commands and Options
#------------------------------
MKDIR = mkdir -p
RM = rm -rf
ifeq ($(ENV),Windows)
  MKDIR = mkdir
  RM = rmdir /q /s
endif

CC = avr-gcc
CFLAGS = -Wextra -Wall -O2 -MMD -MP -c -DCOMPILING_LIBAVR8_

AR = avr-ar
ARFLAGS = rcs

ifeq ($(TARGETDIR),)
  TARGETDIR = ./
  PROGRAM = $(TARGET)
else
  PROGRAM = $(TARGETDIR)/$(TARGET)
endif

ifeq ($(ENV),Windows)
  SRCDIRFILES = $(shell dir /s /b $(subst /,\,$(SRCDIR)))
  SRCDIRFILES := $(patsubst $(shell cd)\\%,./%,$(SRCDIRFILES))
  SRCDIRFILES := $(subst \,/,$(SRCDIRFILES))
else
  SRCDIRFILES = $(shell find $(SRCDIR))
endif

SRCS = $(filter $(SRCSUFFIX),$(SRCDIRFILES))
OBJS =  $(patsubst $(SRCDIR)%,$(OBJDIR)%,$(SRCS))
OBJS := $(patsubst $(SRCSUFFIX),$(OBJSUFFIX),$(OBJS))
DEPS =  $(patsubst $(OBJSUFFIX),$(DEPSUFFIX),$(OBJS))

OBJDIRS = $(sort $(dir $(OBJS)))

ifeq ($(ENV),Windows)
  MKTARGETDIR = $(MKDIR) $(subst /,\,$(TARGETDIR))
  MKOBJDIRS   = $(MKDIR) $(subst /,\,$(OBJDIRS))

  RMPROGRAM = $(RM) $(subst /,\,$(TARGETDIR))
  RMOBJDIR  = $(RM) $(subst /,\,$(OBJDIR))
else
  MKTARGETDIR = $(MKDIR) $(TARGETDIR)
  MKOBJDIRS   = $(MKDIR) $(OBJDIRS)

  RMPROGRAM = $(RM) $(PROGRAM)
  RMOBJDIR  = $(RM) $(OBJDIR)
endif


#------------------------------
# Processes
#------------------------------

all: create-dirs $(PROGRAM)

create-dirs:
ifneq ($(TARGETDIR),)
	@[ -d $(TARGETDIR) ] || $(MKTARGETDIR)
endif
ifneq ($(OBJDIRS),)
	@[ -d "$(OBJDIRS)" ] || $(MKOBJDIRS)
endif

$(PROGRAM): $(OBJS)
	$(AR) $(ARFLAGS) $(PROGRAM) $(OBJS)

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $<

clean:
	@$(RMPROGRAM)
	@$(RMOBJDIR)

#------------------------------
# Check variables
#------------------------------

check-vars:
	@echo ENV         = $(ENV)

	@echo TARGETDIR   = $(TARGETDIR)
	@echo INCDIR      = $(INCDIR)
	@echo SRCDIR      = $(SRCDIR)
	@echo OBJDIR      = $(OBJDIR)

	@echo TARGET      = $(TARGET)

	@echo INCLUDES    = $(INCLUDES)

	@echo SRCSUFFIX   = $(SRCSUFFIX)
	@echo OBJSUFFIX   = $(OBJSUFFIX)
	@echo DEPSUFFIX   = $(DEPSUFFIX)

	@echo MKDIR       = $(MKDIR)
	@echo RM          = $(RM)

	@echo CC          = $(CC)
	@echo CFLAGS      = $(CFLAGS)

	@echo AR          = $(AR)
	@echo ARFLAGS     = $(ARFLAGS)

	@echo PROGRAM     = $(PROGRAM)

	@echo SRCDIRFILES = $(SRCDIRFILES)
	@echo SRCS        = $(SRCS)
	@echo OBJS        = $(OBJS)
	@echo DEPS        = $(DEPS)

	@echo OBJDIRS     = $(OBJDIRS)

	@echo MKTARGETDIR = $(MKTARGETDIR)
	@echo MKOBJDIRS   = $(MKOBJDIRS)
	@echo RMPROGRAM   = $(RMPROGRAM)
	@echo RMOBJDIR    = $(RMOBJDIR)

-include $(DEPS)
