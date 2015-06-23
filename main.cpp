#include <daneel/daneel.hpp>

#include <iostream>
#include <vector>

std::vector<std::string> unique(const std::vector<std::string>& input)
{
  std::vector<std::string> values = input;
  std::sort(values.begin(), values.end());
  auto last = std::unique(values.begin(), values.end());
  values.erase(last, values.end());
  return values;
}

class MyRequestHandler final : public daneel::RequestHandler
{
  public:

    daneel::Response handleRequest(const std::vector<std::string>& params)
    {
      daneel::Response response;
      response.addResults( unique( params ) );
      return response;
    }
};

int main(int argc, char** argv)
{
  daneel::Daneel<MyRequestHandler>::start(argc, argv);

  return EXIT_SUCCESS;
}

