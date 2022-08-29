vector<pair<int, int>> fatora(int x) {
  map<int, int> expoentes;
  while(x > 1) {
    expoentes[ lp[x] ]++; // aumentamos o expoente do primo lp[x] em 1 na resposta
    x /= lp[x];
  }
  vector<pair<int, int>> ans;
  for(pair<int, int> p : expoentes)
    ans.emplace_back(p);
  return ans;
}