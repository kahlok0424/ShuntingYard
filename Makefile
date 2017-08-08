.PHONY: clean All

All:
	@echo "----------Building project:[ ShuntingYard - Debug ]----------"
	@"$(MAKE)" -f  "ShuntingYard.mk"
clean:
	@echo "----------Cleaning project:[ ShuntingYard - Debug ]----------"
	@"$(MAKE)" -f  "ShuntingYard.mk" clean
