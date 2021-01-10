UNAME := $(shell uname -o)

ifeq ($(UNAME),Msys)
	TARGET_EXEC ?= miitoumii.exe
else
	TARGET_EXEC ?= miitoumii
endif

BUILD_DIR ?= ./bin

SRC_DIRS ?= ./src

ifeq ($(UNAME),Msys)
# Set compilers to MinGW64 compilers
CC := x86_64-w64-mingw32-gcc
CXX := x86_64-w64-mingw32-g++
else
CC := gcc
CXX := g++
endif

# C flags
CFLAGS := -std=c11

# C++ flags
CXXFLAGS := -std=gnu++17

# C/C++ flags
CPPFLAGS := -Wall -Wno-maybe-uninitialized -Wno-sign-compare -Wno-switch-enum -Wno-switch -Wno-deprecated-declarations -DKS_STR_ENCODING_NONE -DCPPGLOB_BUILDING $(shell pkg-config --cflags fmt libcurl) -I./include -I./src/third_party -fdata-sections -ffunction-sections

# Linker flags
LDFLAGS := $(shell pkg-config --libs fmt libcurl) -Wl,--gc-sections

# All the dang libraries I need to include
CPPFLAGS += -I./lib/cryptopp -I./lib/oead/src/include -I./lib/ZXing/core/src -I./lib/oead/lib/abseil -I./lib/oead/lib/EasyIterator/include -I./lib/oead/lib/libyaml/include -I./lib/oead/lib/nonstd -I./lib/oead/lib/ordered-map/include -I./lib/oead/lib/rapidyaml/src -I./lib/oead/lib/zlib-ng
LDFLAGS += \
	-L./lib/cryptopp \
	-L./lib/oead/build/lib/abseil/absl/base \
	-L./lib/oead/build/lib/abseil/absl/container \
	-L./lib/oead/build/lib/abseil/absl/debugging \
	-L./lib/oead/build/lib/abseil/absl/flags \
	-L./lib/oead/build/lib/abseil/absl/hash \
	-L./lib/oead/build/lib/abseil/absl/numeric \
	-L./lib/oead/build/lib/abseil/absl/random \
	-L./lib/oead/build/lib/abseil/absl/status \
	-L./lib/oead/build/lib/abseil/absl/strings \
	-L./lib/oead/build/lib/abseil/absl/synchronization \
	-L./lib/oead/build/lib/abseil/absl/time \
	-L./lib/oead/build/lib/abseil/absl/types \
	-L./lib/oead/build/lib/libyaml \
	-L./lib/oead/build/lib/rapidyaml \
	-L./lib/oead/build/lib/rapidyaml/subprojects/c4core/build \
	-L./lib/oead/build/lib/zlib-ng \
	-L./lib/oead/build \
	-L./lib/ZXing/bin/core \
	-loead \
	-loead_res \
	-labsl_hash \
	-labsl_strings \
	-labsl_strings_internal \
	-labsl_str_format_internal \
	-labsl_exponential_biased \
	-labsl_log_severity \
	-labsl_malloc_internal \
	-labsl_periodic_sampler \
	-labsl_raw_logging_internal \
	-labsl_scoped_set_env \
	-labsl_spinlock_wait \
	-labsl_strerror \
	-labsl_throw_delegate \
	-labsl_hashtablez_sampler \
	-labsl_raw_hash_set \
	-labsl_debugging_internal \
	-labsl_demangle_internal \
	-labsl_examine_stack \
	-labsl_failure_signal_handler \
	-labsl_leak_check \
	-labsl_leak_check_disable \
	-labsl_stacktrace \
	-labsl_symbolize \
	-labsl_flags \
	-labsl_flags_commandlineflag \
	-labsl_flags_commandlineflag_internal \
	-labsl_flags_config \
	-labsl_flags_internal \
	-labsl_flags_marshalling \
	-labsl_flags_parse \
	-labsl_flags_private_handle_accessor \
	-labsl_flags_program_name \
	-labsl_flags_reflection \
	-labsl_flags_usage \
	-labsl_flags_usage_internal \
	-labsl_city \
	-labsl_wyhash \
	-labsl_int128 \
	-labsl_random_distributions \
	-labsl_random_internal_distribution_test_util \
	-labsl_random_internal_platform \
	-labsl_random_internal_pool_urbg \
	-labsl_random_internal_randen \
	-labsl_random_internal_randen_hwaes \
	-labsl_random_internal_randen_hwaes_impl \
	-labsl_random_internal_randen_slow \
	-labsl_random_internal_seed_material \
	-labsl_random_seed_gen_exception \
	-labsl_random_seed_sequences \
	-labsl_status \
	-labsl_statusor \
	-labsl_cord \
	-labsl_graphcycles_internal \
	-labsl_synchronization \
	-labsl_civil_time \
	-labsl_time \
	-labsl_time_zone \
	-labsl_bad_any_cast_impl \
	-labsl_bad_optional_access \
	-labsl_bad_variant_access \
	-labsl_base \
	-lyaml \
	-lryml \
	-lc4core \
	-lzlib \
	-lcryptopp \
	-lZXing

ifeq ($(UNAME),Msys)
	# Needed for sockets on windows
	LDFLAGS += -lws2_32
endif

ifeq ($(BUILD),release)
	# "Release" build - optimization, and no debug symbols
	CPPFLAGS += -O3 -s -DNDEBUG
else
	# "Debug" build - no optimization, and debugging symbols
	CPPFLAGS += -Og -g -ggdb -DDEBUG
endif

ifeq ($(ARCH),32)
	CPPFLAGS += -m32
	LDFLAGS += -m32
else
	#CXXFLAGS += 
endif

ifeq ($(UNAME),Msys)
SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s -or -name *.rc)
else
SRCS := $(shell find $(SRC_DIRS) -name *.cpp -or -name *.c -or -name *.s)
endif

OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))

CPPFLAGS ?= $(INC_FLAGS) -MMD -MP

all: $(BUILD_DIR)/$(TARGET_EXEC)

ifeq ($(UNAME),Msys)
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)
	# Copy required DLLs to folder
	ldd $(BUILD_DIR)/$(TARGET_EXEC) | grep '\/mingw.*\.dll' -o | xargs -I{} cp -n "{}" $(BUILD_DIR)
else
$(BUILD_DIR)/$(TARGET_EXEC): $(OBJS)
	$(CXX) $(OBJS) -o $@ $(LDFLAGS)
endif

# assembly
$(BUILD_DIR)/%.s.o: %.s
	$(MKDIR_P) $(dir $@)
	$(AS) $(ASFLAGS) -c $< -o $@

# c source
$(BUILD_DIR)/%.c.o: %.c
	$(MKDIR_P) $(dir $@)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

# c++ source
$(BUILD_DIR)/%.cpp.o: %.cpp
	$(MKDIR_P) $(dir $@)
	$(CXX) $(CPPFLAGS) $(CXXFLAGS) -c $< -o $@

ifeq ($(UNAME),Msys)
# Windows RES file
$(BUILD_DIR)/%.rc.o: %.rc
	$(MKDIR_P) $(dir $@)
	windres $< $@
endif


.PHONY: all clean

clean:
	$(RM) -r $(BUILD_DIR)

-include $(DEPS)

MKDIR_P ?= mkdir -p