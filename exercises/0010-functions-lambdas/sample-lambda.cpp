void main()
{
  std::cout << "lambda" << std::endl;
  int x = 0;
  auto sample = [&x](int &n)
  {
    n -= 1;
    x += n;
  };
  ptf::applier2(v, 5, sample);
}
