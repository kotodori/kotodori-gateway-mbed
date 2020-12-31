include .env

OUT_DIR := BUILD
TARGET := $(OUT_DIR)/

.PHONY: all clean
all:
	mbed compile

deploy: $(TARGET)
	mbed compile
	./scripts/deploy $(DEPLOY_DIR)

clean:
	rm -rf $(OUT_DIR)
