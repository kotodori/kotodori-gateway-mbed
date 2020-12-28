include .env

OUT_DIR := BUILD
TARGET := $(OUT_DIR)/

.PHONY: all clean
all: $(TARGET)

deploy: $(TARGET)
	mbed compile
	./scripts/deploy $(DEPLOY_DIR)

$(TARGET):
	mbed compile

clean:
	rm -rf $(OUT_DIR)
