#----------------------------------------------------------------------------------------------------------------------#
# Project name and installation directories                                                                            #
#----------------------------------------------------------------------------------------------------------------------#
PROJECT_NAME        := celya
BINARY_FILE         := lib$(PROJECT_NAME).so
INSTALL_DIR         := ~/.$(PROJECT_NAME)
LINK_BINARY_DIR     := /usr/lib
LINK_INCLUDE_DIR    := /usr/include

#----------------------------------------------------------------------------------------------------------------------#
# Source files                                                                                                         #
#----------------------------------------------------------------------------------------------------------------------#
INCLUDE_DIR         := include
SOURCE_DIR          := source
BUILD_DIR           := build
H_FILES             := $(INCLUDE_DIR)/$(PROJECT_NAME).h $(wildcard $(INCLUDE_DIR)/$(PROJECT_NAME)/*.h)
C_FILES             := $(wildcard $(SOURCE_DIR)/*/*.c)
O_FILES             := $(C_FILES:$(SOURCE_DIR)/%.c=$(BUILD_DIR)/%.o)

#----------------------------------------------------------------------------------------------------------------------#
# Options for code generation                                                                                          #
#----------------------------------------------------------------------------------------------------------------------#
INCLUDES_FLAGS      := -I $(INCLUDE_DIR)/
LIBRARIES_FLAGS     :=
C_FLAGS             := -Wall -Werror -Wextra -O3 -fpic
LD_FLAGS            := -shared

#----------------------------------------------------------------------------------------------------------------------#
# Commands                                                                                                             #
#----------------------------------------------------------------------------------------------------------------------#
.PHONY : all, clean, deploy
all : $(BUILD_DIR)/$(BINARY_FILE)
	rm -frv $(BUILD_DIR)/$(INCLUDE_DIR)
	cp -rv $(INCLUDE_DIR) $(BUILD_DIR)
clean :
	rm -rv $(BUILD_DIR)
deploy : all
	mkdir -pv $(INSTALL_DIR)
	rm -frv $(INSTALL_DIR)/$(BINARY_FILE) $(INSTALL_DIR)/$(INCLUDE_DIR)
	cp -rv $(BUILD_DIR)/$(BINARY_FILE) $(INSTALL_DIR)
	cp -rv $(BUILD_DIR)/$(INCLUDE_DIR) $(INSTALL_DIR)
	sudo ln -fsv $(INSTALL_DIR)/$(BINARY_FILE) $(LINK_BINARY_DIR)/$(BINARY_FILE)
	sudo ln -fsv $(INSTALL_DIR)/$(INCLUDE_DIR)/* $(LINK_INCLUDE_DIR)

#----------------------------------------------------------------------------------------------------------------------#
# Dependencies                                                                                                         #
#----------------------------------------------------------------------------------------------------------------------#
$(BUILD_DIR)/%.o : $(SOURCE_DIR)/%.c
	mkdir -pv $(dir $@)
	gcc -v $(C_FLAGS) -c $< -o $@ $(INCLUDES_FLAGS)
$(BUILD_DIR)/$(BINARY_FILE) : $(O_FILES)
	gcc -v $(LD_FLAGS) $^ -o $@ $(LIBRARIES_FLAGS)
