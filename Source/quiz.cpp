#include "../Include/quiz.h"

void startQuiz()
{
    std::vector<Quiz> quiz;
    readQuizData(quiz);

    int cityNum;
    std::cout << "Izaberi grad" << std::endl;
    for (int i = 0; i < 4; i++)
    {
        std::cout << i + 1 << " " << quiz[i].getCity() << std::endl;
    }
    do
    {
        std::cout << "Unesi broj" << std::endl;
        std::cin >> cityNum;
        std::cout << std::endl;
    } while (cityNum < 1 || cityNum > 4);

    for (int i = 0; i < 10; i++)
    {
        quiz[cityNum - 1].printQuestion(i);
        quiz[cityNum - 1].answerQuestion(i);
    }

    int correct = 0;
    for (int i = 0; i < 10; i++)
    {
        quiz[cityNum - 1].printAll(i, correct);
    }

    if (correct == 0)
        std::cout << "Niste odgovorili tacno ni na jedno pitanje.";

    else if (correct == 1)
        std::cout << "Odgovorili ste tacno na jedno pitanje.";

    else
        std::cout << "Odgovorili ste tacno na " << correct << " pitanja od " << 10 << ".";
}

//funkzija za konverziju stringa povucenog iz datoteke u bool tip
bool convertToBool(std::string str)
{
    return str == "true";
}

void readQuizData(std::vector<Quiz> &quiz)
{
    //datoteka
    std::ifstream file("./Database/quiz.txt");

    int i = 0;

    std::string line, city, question, answer, correctStr, description;
    bool correct;

    for (int i = 0; i < 4; i++)
    {
        Quiz q;
        getline(file, line);
        //parsiranje stringa
        std::stringstream lineStream(line);

        std::getline(lineStream, city, '|');
        q.setCity(city);

        for (int j = 0; j < 10; j++)
        {
            getline(file, line);
            std::stringstream lineStream0(line);

            std::getline(lineStream0, question, '|');
            q.array[j].setQuestion(question);

            getline(file, line);
            std::stringstream lineStream1(line);
            for (int k = 0; k < 3; k++)
            {
                std::getline(lineStream1, answer, ',');

                std::getline(lineStream1, correctStr, '|');
                correct = convertToBool(correctStr);

                q.array[j].setAnswer(answer, correct, k);
            }

            getline(file, line);
            std::stringstream lineStream2(line);

            std::getline(lineStream2, description, '|');
            q.array[j].setDescription(description);
        }

        quiz.push_back(q);
        getline(file, line);
    }
}

//ispisivanje jednog pitanja i ponudjenih odgovora, prilikom postavljanja pitanja
void Quiz::printQuestion(int index)
{
    std::cout << array[index].getQuestion() << std::endl;
    std::cout << "[1] " << array[index].getAnswer(0) << "  [2] " << array[index].getAnswer(1) << "  [3]" << array[index].getAnswer(2) << std::endl;
}

// krajnji ispis tacnih odgovora i zanimljivosti
void Quiz::printAll(int index, int &correct)
{
    std::cout << array[index].getQuestion() << std::endl;
    std::cout << "Tacan odgovor je: ";
    array[index].printCorrect();
    std::cout << "Odgovorili ste" << (array[index].getAnswered() ? " tacno." : " netacno.") << std::endl
              << std::endl;
    std::cout << array[index].getDescription() << std::endl
              << std::endl
              << std::endl;

    if (array[index].getAnswered())
        correct++;
}

// odgovor na pitanje i ispitivanje tacnosti odgovora
void Quiz::answerQuestion(int index)
{
    int answer;
    std::cout << "Unesi broj:" << std::endl;
    std::cin >> answer;
    std::cout << std::endl;

    array[index].setAnswered(array[index].getCorrect(answer));
}

//ispis tacnog odgovora, pri ispisu kviza
void QuizQuestion::printCorrect()
{
    for (int i = 0; i < 3; i++)
        if (this->getCorrect(i))
            std::cout << this->getAnswer(i) << std::endl;
}

void Answer::setAnswer(std::string answer)
{
    this->answer = answer;
}

void Answer::setCorrect(bool correct)
{
    this->correct = correct;
}

std::string Answer::getAnswer()
{
    return answer;
}

bool Answer::getCorrect()
{
    return correct;
}

void QuizQuestion::setQuestion(std::string question)
{
    this->question = question;
}

void QuizQuestion::setDescription(std::string descripcion)
{
    this->descripcion = descripcion;
}

void QuizQuestion::setAnswer(std::string answer, bool correct, int index)
{
    this->answers[index].setAnswer(answer);
    this->answers[index].setCorrect(correct);
}

std::string QuizQuestion::getQuestion()
{
    return question;
}

std::string QuizQuestion::getDescription()
{
    return descripcion;
}

std::string QuizQuestion::getAnswer(int index)
{
    return answers[index].getAnswer();
}

bool QuizQuestion::getCorrect(int index)
{
    return answers[index].getCorrect();
}

void Quiz::setCity(std::string city)
{
    this->city = city;
}

void QuizQuestion::setAnswered(bool answered)
{
    this->answered = answered;
}

std::string Quiz::getCity()
{
    return city;
}

bool QuizQuestion::getAnswered()
{
    return answered;
}