.PHONY: clean All

All:
	@echo "----------Building project:[ BuildYourOwnLisp - Debug ]----------"
	@$(MAKE) -f  "BuildYourOwnLisp.mk"
clean:
	@echo "----------Cleaning project:[ BuildYourOwnLisp - Debug ]----------"
	@$(MAKE) -f  "BuildYourOwnLisp.mk" clean
