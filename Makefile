.PHONY: clean All

All:
	@echo "----------Building project:[ Hangman_Game - Debug ]----------"
	@cd "Hangman_Game" && "$(MAKE)" -f  "Hangman_Game.mk"
clean:
	@echo "----------Cleaning project:[ Hangman_Game - Debug ]----------"
	@cd "Hangman_Game" && "$(MAKE)" -f  "Hangman_Game.mk" clean
