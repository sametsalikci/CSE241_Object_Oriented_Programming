/* exception.h
# 
# AUTHOR : MEHMET MAZHAR SALIKCI
# NUMBER : 111044050
# HOMEWORK : 08
# FILE : exception.h
# ------INTRODUCTION:
# Bu programın düzgün çalışabilmesi için beklenmedik durumlarda ortaya çıkan durumları
# kontrol etmek için kendimize ait bir exception sınıfı oluşturduk.Bu sınıf search,add ve
# remove fonksiyonları çalıştığında ortaya çıkacak hatalı durumları handle etmek için
# oluşturulan özel bir tiptir.
#	
*/
# ifndef EXCEPTION_H
# define EXCEPTION_H
# include <exception>
# include <string>
  using namespace std;

namespace MMS
{
	class ExceptionClass : public std::exception
	{
	public:
		ExceptionClass(const std::string message = "An exception occured!"){
			this->message = message;
		}
		void printMesseage(){
			cout << "An exception occured!" << endl;
		}
		~ExceptionClass() throw(){
		
		}
		const char* what() const throw(){
			return this->message.c_str();
		}
	private:
		std::string message;
	};
}
#endif//EXCEPTION_H