################################################################################
#                                   VARIABLES                                  #
################################################################################

CXX         := c++
CXXFLAGS    := -Werror -Wall -Wextra -std=c++20 -MMD -MP
CPPFLAGS    := -Iinclude

BIN_DIR     := bin/tests
OBJ_DIR     := .obj/tests

TEST_SRCS   := $(sort $(wildcard tests/*.cpp))
TEST_BINS   := $(patsubst tests/%.cpp,$(BIN_DIR)/%,$(TEST_SRCS))
TEST_OBJS   := $(patsubst tests/%.cpp,$(OBJ_DIR)/%.o,$(TEST_SRCS))
TEST_DEPS   := $(TEST_OBJS:.o=.d)

################################################################################
#                                    COLORS                                    #
################################################################################

COM_COLOR   = \033[0;34m
OBJ_COLOR   = \033[0;36m
OK_COLOR    = \033[0;32m
ERROR_COLOR = \033[0;31m
WARN_COLOR  = \033[0;33m
NO_COLOR    = \033[m

OK_STRING    = "[OK]"
ERROR_STRING = "[ERROR]"
WARN_STRING  = "[WARNING]"
COM_STRING   = "Compiling"

define run_and_report
printf "%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)$(NO_COLOR)\r"; \
	$(1) > $@.log 2>&1; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
		cat $@.log; \
		rm -f $@.log; \
		exit $$RESULT; \
	elif [ -s $@.log ]; then \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)" "$(WARN_COLOR)$(WARN_STRING)$(NO_COLOR)\n"; \
		cat $@.log; \
	else \
		printf "%-60b%b" "$(COM_COLOR)$(COM_STRING) $(OBJ_COLOR)$(@F)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
	fi; \
	rm -f $@.log
endef

define run_test_binary
printf "%b" "$(COM_COLOR)Running $(OBJ_COLOR)$(1)$(NO_COLOR)\r"; \
	./$(1) > $(1).log 2>&1; \
	RESULT=$$?; \
	if [ $$RESULT -ne 0 ]; then \
		printf "%-60b%b" "$(COM_COLOR)Running $(OBJ_COLOR)$(1)" "$(ERROR_COLOR)$(ERROR_STRING)$(NO_COLOR)\n"; \
		cat $(1).log; \
		rm -f $(1).log; \
		exit $$RESULT; \
	elif [ -s $(1).log ]; then \
		printf "%-60b%b" "$(COM_COLOR)Running $(OBJ_COLOR)$(1)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
		cat $(1).log; \
	else \
		printf "%-60b%b" "$(COM_COLOR)Running $(OBJ_COLOR)$(1)" "$(OK_COLOR)$(OK_STRING)$(NO_COLOR)\n"; \
	fi; \
	rm -f $(1).log
endef

################################################################################
#                                  BUILD RULES                                 #
################################################################################

-include $(TEST_DEPS)

all: $(TEST_BINS)

$(BIN_DIR):
	@mkdir -p $@

$(OBJ_DIR):
	@mkdir -p $@

$(BIN_DIR)/%: COM_STRING = Linking
$(BIN_DIR)/%: $(OBJ_DIR)/%.o | $(BIN_DIR)
	@$(call run_and_report,$(CXX) $(CXXFLAGS) $(CPPFLAGS) $< -o $@)

$(OBJ_DIR)/%.o: COM_STRING = Compiling
$(OBJ_DIR)/%.o: tests/%.cpp | $(OBJ_DIR)
	@$(call run_and_report,$(CXX) $(CXXFLAGS) $(CPPFLAGS) -c $< -o $@)

################################################################################
#                                    TARGETS                                   #
################################################################################

test: all
	@set -e; \
	for test_bin in $(TEST_BINS); do \
		$(call run_test_binary,$$test_bin); \
	done

clean: COM_STRING = Cleaning
clean:
	@$(call run_and_report,rm -rf .obj)

fclean: COM_STRING = Cleaning
fclean: clean
	@$(call run_and_report,rm -rf bin)

re: fclean all

help:
	@echo "Usage:"
	@echo "  make          - compile all tests"
	@echo "  make test     - compile and run all tests"
	@echo "  make clean    - remove object files"
	@echo "  make fclean   - remove object files and binaries"
	@echo "  make re       - rebuild everything"

.PHONY: all test clean fclean re help
