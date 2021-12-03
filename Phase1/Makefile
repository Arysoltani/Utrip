CC = g++ -std=c++11

OBJECT_FILES = main.o CsvFile.o Hotel.o Hotels.o Room.o HotelRooms.o DataBase.o HotelReservationInterface.o Filter.o User.o Reserve.o Exceptions.o Comment.o Ratings.o CommandParser.o GetCommandParser.o CommandHandlerInterface.o PostCommandParser.o Rating.o HotelSort.o

all:utrip.out

utrip.out: $(OBJECT_FILES)
		$(CC) $(OBJECT_FILES) -o utrip.out

main.o: main.cpp DataBase.hpp HotelReservationInterface.hpp
	$(CC) -c main.cpp -o main.o

CsvFile.o: CsvFile.cpp CsvFile.hpp
	$(CC) -c CsvFile.cpp -o CsvFile.o

Hotel.o: Hotel.cpp Hotel.hpp Room.hpp Comment.hpp Ratings.hpp
	$(CC) -c Hotel.cpp -o Hotel.o

Hotels.o: Hotels.cpp Hotels.hpp Exceptions.hpp
	$(CC) -c Hotels.cpp -o Hotels.o

Room.o: Room.cpp Room.hpp
	$(CC) -c Room.cpp -o Room.o

HotelRooms.o: HotelRooms.cpp HotelRooms.hpp Exceptions.hpp
	$(CC) -c HotelRooms.cpp -o HotelRooms.o

DataBase.o: DataBase.cpp DataBase.hpp Hotels.hpp CsvFile.hpp
	$(CC) -c DataBase.cpp -o DataBase.o

HotelReservationInterface.o: HotelReservationInterface.cpp HotelReservationInterface.hpp DataBase.hpp User.hpp HotelSort.hpp
	$(CC) -c HotelReservationInterface.cpp -o HotelReservationInterface.o

LoginUserManagment.o: LoginUserManagment.cpp LoginUserManagment.hpp DataBase.hpp Hotels.hpp Hotel.hpp CommandHandlingTools.hpp
	$(CC) -c LoginUserManagment.cpp -o LoginUserManagment.o

CommandHandlingTools.o: CommandHandlingTools.cpp CommandHandlingTools.hpp
	$(CC) -c CommandHandlingTools.cpp -o CommandHandlingTools.o

Filter.o: Filter.cpp Filter.hpp Hotels.hpp
	$(CC) -c Filter.cpp -o Filter.o

User.o: User.cpp User.hpp Reserve.hpp Exceptions.hpp
	$(CC) -c User.cpp -o User.o

Reserve.o: Reserve.cpp Reserve.hpp Hotel.hpp Room.hpp
	$(CC) -c Reserve.cpp -o Reserve.o

Exceptions.o: Exceptions.cpp Exceptions.hpp
	$(CC) -c Exceptions.cpp -o Exceptions.o

Comment.o: Comment.cpp Comment.hpp User.hpp
	$(CC) -c Comment.cpp -o Comment.o

Ratings.o: Ratings.cpp Ratings.hpp Rating.hpp
	$(CC) -c Ratings.cpp -o Ratings.o

GetCommandParser.o: GetCommandParser.cpp GetCommandParser.hpp HotelReservationInterface.hpp CommandParser.hpp Exceptions.hpp
	$(CC) -c GetCommandParser.cpp -o GetCommandParser.o

CommandParser.o: CommandParser.cpp CommandParser.hpp
	$(CC) -c CommandParser.cpp -o CommandParser.o

CommandHandlerInterface.o : CommandHandlerInterface.cpp CommandHandlerInterface.hpp HotelReservationInterface.hpp GetCommandParser.hpp PostCommandParser.hpp Exceptions.hpp
	$(CC) -c CommandHandlerInterface.cpp -o CommandHandlerInterface.o

PostCommandParser.o: PostCommandParser.cpp PostCommandParser.hpp HotelReservationInterface.hpp CommandParser.hpp Exceptions.hpp HotelSort.hpp 
	$(CC) -c PostCommandParser.cpp -o PostCommandParser.o

Rating.o: Rating.cpp Rating.hpp
	$(CC) -c Rating.cpp -o Rating.o

HotelSort.o: HotelSort.cpp HotelSort.hpp
	$(CC) -c HotelSort.cpp -o HotelSort.o

clean:
	rm *.o *.out
