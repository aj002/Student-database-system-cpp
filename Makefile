.PHONY: clean All

All:
	@echo "----------Building project:[ Student_Database_System_CPP - Debug ]----------"
	@"$(MAKE)" -f  "Student_Database_System_CPP.mk"
clean:
	@echo "----------Cleaning project:[ Student_Database_System_CPP - Debug ]----------"
	@"$(MAKE)" -f  "Student_Database_System_CPP.mk" clean
