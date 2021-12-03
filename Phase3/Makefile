CC = g++ -std=c++11
DIR_LOGIC = ServerLogic
BUILD_DIR=build
WEB_DIR=WebServer

OBJECT_FILES = $(BUILD_DIR)/main.o $(BUILD_DIR)/CsvFile.o $(BUILD_DIR)/Hotel.o $(BUILD_DIR)/Hotels.o $(BUILD_DIR)/Room.o $(BUILD_DIR)/HotelRooms.o $(BUILD_DIR)/DataBase.o $(BUILD_DIR)/HotelReservationInterface.o $(BUILD_DIR)/Filter.o $(BUILD_DIR)/User.o $(BUILD_DIR)/Reserve.o $(BUILD_DIR)/Exceptions.o $(BUILD_DIR)/Comment.o $(BUILD_DIR)/Ratings.o $(BUILD_DIR)/CommandParser.o $(BUILD_DIR)/GetCommandParser.o $(BUILD_DIR)/CommandHandlerInterface.o $(BUILD_DIR)/PostCommandParser.o $(BUILD_DIR)/Rating.o $(BUILD_DIR)/HotelSort.o $(BUILD_DIR)/template_parser.o $(BUILD_DIR)/route.o $(BUILD_DIR)/response.o $(BUILD_DIR)/request.o $(BUILD_DIR)/utilities.o $(BUILD_DIR)/server.o $(BUILD_DIR)/handlers.o $(WEB_DIR)/UsersOnSite.o $(BUILD_DIR)/HotelPageHandler.o $(WEB_DIR)/SignupHandler.o $(WEB_DIR)/MoneyAmountHandler.o

all:utrip.out

utrip.out: $(OBJECT_FILES)
		$(CC) $(OBJECT_FILES) -o utrip.out

$(BUILD_DIR)/main.o: main.cpp $(DIR_LOGIC)/DataBase.hpp $(DIR_LOGIC)/HotelReservationInterface.hpp server/server.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp $(WEB_DIR)/SignupHandler.hpp
	$(CC) -c main.cpp -o $(BUILD_DIR)/main.o

$(BUILD_DIR)/CsvFile.o: $(DIR_LOGIC)/CsvFile.cpp $(DIR_LOGIC)/CsvFile.hpp
	$(CC) -c $(DIR_LOGIC)/CsvFile.cpp -o $(BUILD_DIR)/CsvFile.o

$(BUILD_DIR)/Hotel.o: $(DIR_LOGIC)/Hotel.cpp $(DIR_LOGIC)/Hotel.hpp $(DIR_LOGIC)/Room.hpp $(DIR_LOGIC)/Comment.hpp $(DIR_LOGIC)/Ratings.hpp
	$(CC) -c $(DIR_LOGIC)/Hotel.cpp -o $(BUILD_DIR)/Hotel.o

$(BUILD_DIR)/Hotels.o: $(DIR_LOGIC)/Hotels.cpp $(DIR_LOGIC)/Hotels.hpp $(DIR_LOGIC)/Exceptions.hpp
	$(CC) -c $(DIR_LOGIC)/Hotels.cpp -o $(BUILD_DIR)/Hotels.o

$(BUILD_DIR)/Room.o: $(DIR_LOGIC)/Room.cpp $(DIR_LOGIC)/Room.hpp
	$(CC) -c $(DIR_LOGIC)/Room.cpp -o $(BUILD_DIR)/Room.o

$(BUILD_DIR)/HotelRooms.o: $(DIR_LOGIC)/HotelRooms.cpp $(DIR_LOGIC)/HotelRooms.hpp $(DIR_LOGIC)/Exceptions.hpp
	$(CC) -c $(DIR_LOGIC)/HotelRooms.cpp -o $(BUILD_DIR)/HotelRooms.o

$(BUILD_DIR)/DataBase.o: $(DIR_LOGIC)/DataBase.cpp $(DIR_LOGIC)/DataBase.hpp $(DIR_LOGIC)/Hotels.hpp $(DIR_LOGIC)/CsvFile.hpp
	$(CC) -c $(DIR_LOGIC)/DataBase.cpp -o $(BUILD_DIR)/DataBase.o

$(BUILD_DIR)/HotelReservationInterface.o: $(DIR_LOGIC)/HotelReservationInterface.cpp $(DIR_LOGIC)/HotelReservationInterface.hpp $(DIR_LOGIC)/DataBase.hpp $(DIR_LOGIC)/User.hpp $(DIR_LOGIC)/HotelSort.hpp
	$(CC) -c $(DIR_LOGIC)/HotelReservationInterface.cpp -o $(BUILD_DIR)/HotelReservationInterface.o

$(BUILD_DIR)/LoginUserManagment.o: $(DIR_LOGIC)/LoginUserManagment.cpp $(DIR_LOGIC)/LoginUserManagment.hpp $(DIR_LOGIC)/DataBase.hpp $(DIR_LOGIC)/Hotels.hpp $(DIR_LOGIC)/Hotel.hpp $(DIR_LOGIC)/CommandHandlingTools.hpp
	$(CC) -c $(DIR_LOGIC)/LoginUserManagment.cpp -o $(BUILD_DIR)/LoginUserManagment.o

$(BUILD_DIR)/CommandHandlingTools.o: $(DIR_LOGIC)/CommandHandlingTools.cpp $(DIR_LOGIC)/CommandHandlingTools.hpp
	$(CC) -c $(DIR_LOGIC)/CommandHandlingTools.cpp -o $(BUILD_DIR)/CommandHandlingTools.o

$(BUILD_DIR)/Filter.o: $(DIR_LOGIC)/Filter.cpp $(DIR_LOGIC)/Filter.hpp $(DIR_LOGIC)/Hotels.hpp
	$(CC) -c $(DIR_LOGIC)/Filter.cpp -o $(BUILD_DIR)/Filter.o

$(BUILD_DIR)/User.o: $(DIR_LOGIC)/User.cpp $(DIR_LOGIC)/User.hpp $(DIR_LOGIC)/Reserve.hpp $(DIR_LOGIC)/Exceptions.hpp
	$(CC) -c $(DIR_LOGIC)/User.cpp -o $(BUILD_DIR)/User.o

$(BUILD_DIR)/Reserve.o: $(DIR_LOGIC)/Reserve.cpp $(DIR_LOGIC)/Reserve.hpp $(DIR_LOGIC)/Hotel.hpp $(DIR_LOGIC)/Room.hpp
	$(CC) -c $(DIR_LOGIC)/Reserve.cpp -o $(BUILD_DIR)/Reserve.o

$(BUILD_DIR)/Exceptions.o: $(DIR_LOGIC)/Exceptions.cpp $(DIR_LOGIC)/Exceptions.hpp
	$(CC) -c $(DIR_LOGIC)/Exceptions.cpp -o $(BUILD_DIR)/Exceptions.o

$(BUILD_DIR)/Comment.o: $(DIR_LOGIC)/Comment.cpp $(DIR_LOGIC)/Comment.hpp $(DIR_LOGIC)/User.hpp
	$(CC) -c $(DIR_LOGIC)/Comment.cpp -o $(BUILD_DIR)/Comment.o

$(BUILD_DIR)/Ratings.o: $(DIR_LOGIC)/Ratings.cpp $(DIR_LOGIC)/Ratings.hpp $(DIR_LOGIC)/Rating.hpp
	$(CC) -c $(DIR_LOGIC)/Ratings.cpp -o $(BUILD_DIR)/Ratings.o

$(BUILD_DIR)/GetCommandParser.o: $(DIR_LOGIC)/GetCommandParser.cpp $(DIR_LOGIC)/GetCommandParser.hpp $(DIR_LOGIC)/HotelReservationInterface.hpp $(DIR_LOGIC)/CommandParser.hpp $(DIR_LOGIC)/Exceptions.hpp
	$(CC) -c $(DIR_LOGIC)/GetCommandParser.cpp -o $(BUILD_DIR)/GetCommandParser.o

$(BUILD_DIR)/CommandParser.o: $(DIR_LOGIC)/CommandParser.cpp $(DIR_LOGIC)/CommandParser.hpp
	$(CC) -c $(DIR_LOGIC)/CommandParser.cpp -o $(BUILD_DIR)/CommandParser.o

$(BUILD_DIR)/CommandHandlerInterface.o : $(DIR_LOGIC)/CommandHandlerInterface.cpp $(DIR_LOGIC)/CommandHandlerInterface.hpp $(DIR_LOGIC)/HotelReservationInterface.hpp $(DIR_LOGIC)/GetCommandParser.hpp $(DIR_LOGIC)/PostCommandParser.hpp $(DIR_LOGIC)/Exceptions.hpp
	$(CC) -c $(DIR_LOGIC)/CommandHandlerInterface.cpp -o $(BUILD_DIR)/CommandHandlerInterface.o

$(BUILD_DIR)/PostCommandParser.o: $(DIR_LOGIC)/PostCommandParser.cpp $(DIR_LOGIC)/PostCommandParser.hpp $(DIR_LOGIC)/HotelReservationInterface.hpp $(DIR_LOGIC)/CommandParser.hpp $(DIR_LOGIC)/Exceptions.hpp $(DIR_LOGIC)/HotelSort.hpp
	$(CC) -c $(DIR_LOGIC)/PostCommandParser.cpp -o $(BUILD_DIR)/PostCommandParser.o

$(BUILD_DIR)/Rating.o: $(DIR_LOGIC)/Rating.cpp $(DIR_LOGIC)/Rating.hpp
	$(CC) -c $(DIR_LOGIC)/Rating.cpp -o $(BUILD_DIR)/Rating.o

$(BUILD_DIR)/HotelSort.o: $(DIR_LOGIC)/HotelSort.cpp $(DIR_LOGIC)/HotelSort.hpp
	$(CC) -c $(DIR_LOGIC)/HotelSort.cpp -o $(BUILD_DIR)/HotelSort.o

$(BUILD_DIR)/template_parser.o: utils/template_parser.cpp utils/template_parser.hpp utils/request.cpp utils/request.hpp utils/utilities.hpp utils/utilities.cpp
	$(CC) -c utils/template_parser.cpp -o $(BUILD_DIR)/template_parser.o

$(BUILD_DIR)/response.o: utils/response.cpp utils/response.hpp utils/include.hpp
	$(CC) -c utils/response.cpp -o $(BUILD_DIR)/response.o

$(BUILD_DIR)/request.o: utils/request.cpp utils/request.hpp utils/include.hpp utils/utilities.hpp
	$(CC) -c utils/request.cpp -o $(BUILD_DIR)/request.o

$(BUILD_DIR)/utilities.o: utils/utilities.cpp utils/utilities.hpp
	$(CC) -c utils/utilities.cpp -o $(BUILD_DIR)/utilities.o

$(BUILD_DIR)/server.o: server/server.cpp server/server.hpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp utils/template_parser.hpp utils/template_parser.cpp
	$(CC) -c server/server.cpp -o $(BUILD_DIR)/server.o

$(BUILD_DIR)/route.o: server/route.cpp server/route.hpp utils/utilities.hpp utils/response.hpp utils/request.hpp utils/include.hpp
	$(CC) -c server/route.cpp -o $(BUILD_DIR)/route.o

$(BUILD_DIR)/handlers.o: $(WEB_DIR)/handlers.cpp $(WEB_DIR)/handlers.hpp $(DIR_LOGIC)/HotelReservationInterface.hpp $(DIR_LOGIC)/DataBase.hpp server/server.hpp
	$(CC) -c $(WEB_DIR)/handlers.cpp -o $(BUILD_DIR)/handlers.o

$(BUILD_DIR)/UsersOnSite.o: $(DIR_LOGIC)/HotelReservationInterface.hpp $(WEB_DIR)/UsersOnSite.cpp $(WEB_DIR)/UsersOnSite.hpp
	$(CC) -c $(WEB_DIR)/UsersOnSite.cpp -o $(BUILD_DIR)/UsersOnSite.o

$(BUILD_DIR)/HotelPageHandler.o: $(WEB_DIR)/HotelPageHandler.cpp $(WEB_DIR)/HotelPageHandler.hpp $(WEB_DIR)/handlers.hpp $(DIR_LOGIC)/HotelReservationInterface.hpp $(DIR_LOGIC)/DataBase.hpp server/server.hpp
	$(CC) -c $(WEB_DIR)/HotelPageHandler.cpp -o $(BUILD_DIR)/HotelPageHandler.o

$(BUILD_DIR)/SignupHandler.o: $(WEB_DIR)/SignupHandler.cpp $(WEB_DIR)/SignupHandler.hpp $(WEB_DIR)/handlers.hpp $(DIR_LOGIC)/HotelReservationInterface.hpp $(DIR_LOGIC)/DataBase.hpp server/server.hpp
	$(CC) -c $(WEB_DIR)/SignupHandler.cpp -o $(BUILD_DIR)/SignupHandler.o

$(BUILD_DIR)/MoneyAmountHandler.o: $(WEB_DIR)/MoneyAmountHandler.cpp $(WEB_DIR)/MoneyAmountHandler.hpp $(WEB_DIR)/handlers.hpp $(DIR_LOGIC)/HotelReservationInterface.hpp $(DIR_LOGIC)/DataBase.hpp server/server.hpp
	$(CC) -c $(WEB_DIR)/MoneyAmountHandler.cpp -o $(BUILD_DIR)/MoneyAmountHandler.o

clean:
	rm $(BUILD_DIR)/*.o *$(BUILD_DIR)/*.out
