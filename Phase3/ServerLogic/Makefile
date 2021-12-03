CC = g++ -std=c++11
DICT_LOGIC = ServerLogic
BUILD_DIR=build

OBJECT_FILES = $(BUILD_DIR)/main.o $(BUILD_DIR)/CsvFile.o $(BUILD_DIR)/Hotel.o $(BUILD_DIR)/Hotels.o $(BUILD_DIR)/Room.o $(BUILD_DIR)/HotelRooms.o $(BUILD_DIR)/DataBase.o $(BUILD_DIR)/HotelReservationInterface.o $(BUILD_DIR)/Filter.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Reserve.o $(BUILD_DIR)/Exceptions.o $(BUILD_DIR)/Comment.o $(BUILD_DIR)/Ratings.o $(BUILD_DIR)/CommandParser.o $(BUILD_DIR)/GetCommandParser.o $(BUILD_DIR)/CommandHandlerInterface.o $(BUILD_DIR)/PostCommandParser.o $(BUILD_DIR)/Rating.o $(BUILD_DIR)/HotelSort.o

all: $(BUILD_DIR)/utrip.out

$(BUILD_DIR)/utrip.out: $(OBJECT_FILES)
		$(CC) $(OBJECT_FILES) -o $(BUILD_DIR)/utrip.out

$(BUILD_DIR)/main.o: $(DICT_LOGIC)/main.cpp $(DICT_LOGIC)/DataBase.hpp $(DICT_LOGIC)/HotelReservationInterface.hpp
	$(CC) -c $(DICT_LOGIC)/main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/CsvFile.o: $(DICT_LOGIC)/CsvFile.cpp $(DICT_LOGIC)/CsvFile.hpp
	$(CC) -c $(DICT_LOGIC)/CsvFile.cpp -o $(BUILD_DIR)/CsvFile.o

$(BUILD_DIR)/Hotel.o: $(DICT_LOGIC)/Hotel.cpp $(DICT_LOGIC)/Hotel.hpp $(DICT_LOGIC)/Room.hpp $(DICT_LOGIC)/Comment.hpp $(DICT_LOGIC)/Ratings.hpp
	$(CC) -c $(DICT_LOGIC)$(DICT_LOGIC)//Hotel.cpp -o $(BUILD_DIR)/Hotel.o

$(BUILD_DIR)/Hotels.o: $(DICT_LOGIC)/Hotels.cpp $(DICT_LOGIC)/Hotels.hpp $(DICT_LOGIC)/Exceptions.hpp
	$(CC) -c $(DICT_LOGIC)/Hotels.cpp -o $(BUILD_DIR)/Hotels.o

$(BUILD_DIR)/Room.o: $(DICT_LOGIC)/Room.cpp $(DICT_LOGIC)/Room.hpp
	$(CC) -c $(DICT_LOGIC)/Room.cpp -o $(BUILD_DIR)/Room.o

$(BUILD_DIR)/HotelRooms.o: $(DICT_LOGIC)/HotelRooms.cpp $(DICT_LOGIC)/HotelRooms.hpp $(DICT_LOGIC)/Exceptions.hpp
	$(CC) -c $(DICT_LOGIC)/HotelRooms.cpp -o $(BUILD_DIR)/HotelRooms.o

$(BUILD_DIR)/DataBase.o: $(DICT_LOGIC)/DataBase.cpp $(DICT_LOGIC)/DataBase.hpp $(DICT_LOGIC)/Hotels.hpp $(DICT_LOGIC)/CsvFile.hpp
	$(CC) -c $(DICT_LOGIC)/DataBase.cpp -o $(BUILD_DIR)/DataBase.o

$(BUILD_DIR)/HotelReservationInterface.o: $(DICT_LOGIC)/HotelReservationInterface.cpp $(DICT_LOGIC)/HotelReservationInterface.hpp $(DICT_LOGIC)/DataBase.hpp $(DICT_LOGIC)/User.hpp $(DICT_LOGIC)/HotelSort.hpp
	$(CC) -c $(DICT_LOGIC)/HotelReservationInterface.cpp -o $(BUILD_DIR)/HotelReservationInterface.o

$(BUILD_DIR)/LoginUserManagment.o: $(DICT_LOGIC)/LoginUserManagment.cpp $(DICT_LOGIC)/LoginUserManagment.hpp $(DICT_LOGIC)/DataBase.hpp $(DICT_LOGIC)/Hotels.hpp $(DICT_LOGIC)/Hotel.hpp $(DICT_LOGIC)/CommandHandlingTools.hpp
	$(CC) -c $(DICT_LOGIC)/LoginUserManagment.cpp -o $(BUILD_DIR)/LoginUserManagment.o

$(BUILD_DIR)/CommandHandlingTools.o: $(DICT_LOGIC)/CommandHandlingTools.cpp $(DICT_LOGIC)/CommandHandlingTools.hpp
	$(CC) -c $(DICT_LOGIC)/CommandHandlingTools.cpp -o $(BUILD_DIR)/CommandHandlingTools.o

$(BUILD_DIR)/Filter.o: $(DICT_LOGIC)/Filter.cpp $(DICT_LOGIC)/Filter.hpp $(DICT_LOGIC)/Hotels.hpp
	$(CC) -c $(DICT_LOGIC)/Filter.cpp -o $(BUILD_DIR)/Filter.o

$(BUILD_DIR)/User.o: $(DICT_LOGIC)/User.cpp User.hpp $(DICT_LOGIC)/Reserve.hpp $(DICT_LOGIC)/Exceptions.hpp
	$(CC) -c $(DICT_LOGIC)/User.cpp -o $(BUILD_DIR)/User.o

$(BUILD_DIR)/Reserve.o: $(DICT_LOGIC)/Reserve.cpp $(DICT_LOGIC)/Reserve.hpp $(DICT_LOGIC)/Hotel.hpp $(DICT_LOGIC)/Room.hpp
	$(CC) -c $(DICT_LOGIC)/Reserve.cpp -o $(BUILD_DIR)/Reserve.o

$(BUILD_DIR)/Exceptions.o: $(DICT_LOGIC)/Exceptions.cpp $(DICT_LOGIC)/Exceptions.hpp
	$(CC) -c $(DICT_LOGIC)/Exceptions.cpp -o $(BUILD_DIR)/Exceptions.o

$(BUILD_DIR)/Comment.o: $(DICT_LOGIC)/Comment.cpp $(DICT_LOGIC)/Comment.hpp $(DICT_LOGIC)/User.hpp
	$(CC) -c $(DICT_LOGIC)/Comment.cpp -o $(BUILD_DIR)/Comment.o

$(BUILD_DIR)/Ratings.o: $(DICT_LOGIC)/Ratings.cpp $(DICT_LOGIC)/Ratings.hpp $(DICT_LOGIC)/Rating.hpp
	$(CC) -c $(DICT_LOGIC)/Ratings.cpp -o $(BUILD_DIR)/Ratings.o

$(BUILD_DIR)/GetCommandParser.o: $(DICT_LOGIC)/GetCommandParser.cpp $(DICT_LOGIC)/GetCommandParser.hpp $(DICT_LOGIC)/HotelReservationInterface.hpp $(DICT_LOGIC)/CommandParser.hpp $(DICT_LOGIC)/Exceptions.hpp
	$(CC) -c $(DICT_LOGIC)/GetCommandParser.cpp -o $(BUILD_DIR)/GetCommandParser.o

$(BUILD_DIR)/CommandParser.o: $(DICT_LOGIC)/CommandParser.cpp $(DICT_LOGIC)/CommandParser.hpp
	$(CC) -c $(DICT_LOGIC)/CommandParser.cpp -o $(BUILD_DIR)/CommandParser.o

$(BUILD_DIR)/CommandHandlerInterface.o : $(DICT_LOGIC)/CommandHandlerInterface.cpp $(DICT_LOGIC)/CommandHandlerInterface.hpp $(DICT_LOGIC)/HotelReservationInterface.hpp $(DICT_LOGIC)/GetCommandParser.hpp $(DICT_LOGIC)/PostCommandParser.hpp $(DICT_LOGIC)/Exceptions.hpp
	$(CC) -c CommandHandlerInterface.cpp -o $(BUILD_DIR)/CommandHandlerInterface.o

$(BUILD_DIR)/PostCommandParser.o: $(DICT_LOGIC)/PostCommandParser.cpp $(DICT_LOGIC)/PostCommandParser.hpp $(DICT_LOGIC)/HotelReservationInterface.hpp $(DICT_LOGIC)/CommandParser.hpp $(DICT_LOGIC)/Exceptions.hpp $(DICT_LOGIC)/HotelSort.hpp
	$(CC) -c $(DICT_LOGIC)/PostCommandParser.cpp -o $(BUILD_DIR)/PostCommandParser.o

$(BUILD_DIR)/Rating.o: $(DICT_LOGIC)/Rating.cpp $(DICT_LOGIC)/Rating.hpp
	$(CC) -c $(DICT_LOGIC)/Rating.cpp -o $(BUILD_DIR)/Rating.o

$(BUILD_DIR)/HotelSort.o: $(DICT_LOGIC)/HotelSort.cpp $(DICT_LOGIC)/HotelSort.hpp
	$(CC) -c $(DICT_LOGIC)/HotelSort.cpp -o $(BUILD_DIR)/HotelSort.o

clean:
	rm *.o *.out
