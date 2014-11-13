/* CodeChef, challenge Minesweeper(MINESWPR) 2013.03.08

  To minimize number of "surveys", information from each "survey" should be
  used as much as possible. Remember the number of adjacent cells containing
  mines. Then wherever a mine in the adjacent cell is detected, this number
  is updated. Also wherever it is found that an adjacent cell is empty,
  a counter of empty cells is updated. If "mines" counter is decreased to zero
  or sum of "empty" and "mines" counters is increased to 8, all the remaining
  adjacent cells are either treated "empty" or are neutralized. "ActionCleanup",
  "ActionNeutralize", "ActionDecrement", "ActionDecrement" objects perform this
  accounting.

  Each modification of cell state may affect several adjacent cells, and this
  may continue recursively. Instead of recursion all these updates are done
  by BFS, using "enqueue", "dequeue", and "loop" functions.

  To optimize more, assumptions are made about some cells (whether they are
  empty or contain a mine). Same BFS procedure is used to check these
  assumptions. If any assumption fails, corresponding cell is marked as
  opposite to this  assumption. "ActionTouch" object and "explorePtr/explore"
  linked lists are used to select these cells. "nextExplore", "doneExplore",
  and "checkTheCell" functions check the assumption.

  Initial exploration of the field is done by "doCheckers" function which
  surveys every second cell and allows above procedures to fill almost all
  others.

  If after all these procedures there are some uninvestigated cells, they are
  handled with "doRest" function. When there are at least as much "neutralize"
  possibilities as uninvestigated cells or when all mines are already
  neutralized, "doAllKnown" function completes the task.

  If mine field is too sparse or if there are extra "neutralize" possibilities,
  some pre-processing allows even more optimizations. The field is divided
  into 3x3 blocks and inspected by "doBlocks" function. Then "doBlind" function
  "neutralizes" dense blocks.
 */

#include <iostream>
#include <cstring>

namespace {
  enum {
    NMAX = 50+2, // +2 for borders
    Nil = 255,
  };

  enum Type {
    T_Empty = 0xA,
    T_Border = 0xD,
    T_Unknown = 0xF,
  };

  enum Cmd {
    C_Cleanup,
    C_Neutralize,
    C_Decrement,
    C_Increment,
  };

  enum ExploreState {
    ES_OK,
    ES_Fail,
  };

  unsigned n = 0;
  unsigned m = 0;
  unsigned k = 0;
  unsigned blk = 0;
  unsigned queueNr = 0;
  unsigned unknowns = 0;
  ExploreState exploreState = ES_OK;
  unsigned blockBlind = 6;
  unsigned blockMines[9];

  struct Cell
  {
    unsigned char m; // adjacent mines or type
    unsigned char e; // adjacent empty cells
  };

  struct Link
  {
    unsigned char x;
    unsigned char y;
  };

  struct Task
  {
    unsigned char cmd;
    unsigned char x;
    unsigned char y;
  };

  class Queue
  {
    Task array_[NMAX*NMAX];
    Task* head_;
    Task* tail_;

  public:
    Queue()
      : head_(array_)
      , tail_(array_)
    {}

    bool empty() const
    {
      return head_ == tail_;
    }

    void clear()
    {
      head_ = array_;
      tail_ = array_;
    }

    const Task& tail() const
    {
      return *tail_;
    }

    Task& head()
    {
      return *head_;
    }

    void pop()
    {
      ++tail_;
    }

    void push()
    {
      ++head_;
    }
  };

  Cell field[2][NMAX][NMAX];
  Queue queue[2];
  Link explore[NMAX][NMAX];
  Link explorePtr = {Nil, Nil};

  void init()
  {
    unknowns = n * n;

    for (unsigned i = 0; i <= n+1; ++i)
    {
      field[0][i][0].m = T_Border;
      field[0][i][n+1].m = T_Border;
      field[0][0][i].m = T_Border;
      field[0][n+1][i].m = T_Border;
    }

    for (unsigned i = 1; i <= n; ++i)
      for (unsigned j = 1; j <= n; ++j)
	field[0][i][j].m = T_Unknown;

    for (unsigned i = 1; i <= n; ++i)
      for (unsigned j = 1; j <= n; ++j)
      {
	explore[i][j].x = Nil;
	explore[i][j].y = Nil;
      }
  }

  char survey(unsigned x, unsigned y)
  {
    std::cout << "S " << x-1 << ' ' << y-1 << std::endl;
    char z = 0;
    std::cin >> z;
    return z;
  }

  void neutralize(unsigned x, unsigned y)
  {
    std::cout << "N " << x-1 << ' ' << y-1 << "\n";
    --m;
    --k;
  }

  char down(unsigned char c)
  {
    return static_cast<unsigned char>(c - '0');
  }

  char up(unsigned char c)
  {
    return static_cast<unsigned char>(c + '0');
  }

  void enqueue(Cmd cmd, unsigned x, unsigned y)
  {
    Task& task = queue[queueNr].head();
    task.cmd = static_cast<unsigned char>(cmd);
    task.x = static_cast<unsigned char>(x);
    task.y = static_cast<unsigned char>(y);
    queue[queueNr].push();
  }

  template<class Action>
  void neighborhood(unsigned x, unsigned y)
  {
    Action a;

    a(x-1, y-1);
    a(x-1, y);
    a(x-1, y+1);

    a(x, y-1);
    a(x, y+1);

    a(x+1, y-1);
    a(x+1, y);
    a(x+1, y+1);
  }

  unsigned char isKnown(unsigned x, unsigned y)
  {
    return field[queueNr][x][y].m != T_Unknown;
  }

  void adjacentMines(unsigned x, unsigned y, const Cell& c)
  {
    if (c.m + c.e == 8 && c.m > 0) // all remaining neighbors are mines
    {
      enqueue(C_Neutralize, x, y);
    }
  }

  void neighborCnt(unsigned x, unsigned y)
  {
    Cell& c = field[queueNr][x][y];
    unsigned char total = 0;

    total += isKnown(x-1, y-1);
    total += isKnown(x-1, y);
    total += isKnown(x-1, y+1);

    total += isKnown(x, y-1);
    total += isKnown(x, y+1);

    total += isKnown(x+1, y-1);
    total += isKnown(x+1, y);
    total += isKnown(x+1, y+1);

    c.e = total;
    adjacentMines(x, y, c);
  }

  struct ActionTouch
  {
    void operator () (unsigned x, unsigned y)
    {
      Cell& c = field[queueNr][x][y];

      if (queueNr == 1 || c.m != T_Unknown)
	return;

      Link& link = explore[x][y];
      if (link.x == Nil)
      {
	link = explorePtr;
	explorePtr.x = x;
	explorePtr.y = y;
      }
    }
  };

  void touch(unsigned x, unsigned y)
  {
    neighborhood<ActionTouch>(x, y);
  }

  struct ActionCleanup
  {
    void operator () (unsigned x, unsigned y)
    {
      Cell& c = field[queueNr][x][y];
      if (c.m == T_Unknown)
      {
        c.m = T_Empty;
	enqueue(C_Increment, x, y);

	if (queueNr == 0)
	  --unknowns;
      }
    }
  };

  struct ActionNeutralize
  {
    void operator () (unsigned x, unsigned y)
    {
      Cell& c = field[queueNr][x][y];
      if (c.m == T_Unknown)
      {
        c.m = T_Empty;
	enqueue(C_Decrement, x, y);

	if (queueNr == 0)
	{
	  neutralize(x, y);
	  --unknowns;
	}
      }
    }
  };

  struct ActionDecrement
  {
    void operator () (unsigned x, unsigned y)
    {
      Cell& c = field[queueNr][x][y];

      if (c.m == 0)
      {
	exploreState = ES_Fail;
	return;
      }

      if (c.m < T_Empty)
      {
        --c.m;
	++c.e;
	touch(x, y);
      }

      if (c.m == 0)
	enqueue(C_Cleanup, x, y);
    }
  };

  struct ActionIncrement
  {
    void operator () (unsigned x, unsigned y)
    {
      Cell& c = field[queueNr][x][y];

      if (c.m >= T_Empty)
	return;

      if (c.e + c.m > 7)
      {
	exploreState = ES_Fail;
	return;
      }

      touch(x, y);
      ++c.e;

      adjacentMines(x, y, c);
    }
  };

  void dequeue()
  {
    const Task& task = queue[queueNr].tail();
    switch (task.cmd)
    {
    case C_Cleanup:
      neighborhood<ActionCleanup>(task.x, task.y);
      break;

    case C_Neutralize:
      neighborhood<ActionNeutralize>(task.x, task.y);
      break;

    case C_Decrement:
      neighborhood<ActionDecrement>(task.x, task.y);
      break;

    case C_Increment:
      neighborhood<ActionIncrement>(task.x, task.y);
      break;

    default:
      break;
    }

    queue[queueNr].pop();
  }

  void pushState()
  {
    exploreState = ES_OK;
    ++queueNr;
    std::memcpy(field+1, field, NMAX*NMAX*sizeof(Cell));
  }

  void popState()
  {
    exploreState = ES_OK;
    --queueNr;
  }

  Cell& exploreCell()
  {
    return field[queueNr][explorePtr.x][explorePtr.y];
  }

  bool nextExplore()
  {
    while (explorePtr.x != Nil && exploreCell().m != T_Unknown)
    {
      Link l = explorePtr;
      explorePtr.x = explore[l.x][l.y].x;
      explorePtr.y = explore[l.x][l.y].y;
      explore[l.x][l.y].x = Nil;
      explore[l.x][l.y].y = Nil;
    }

    return explorePtr.x != Nil;
  }

  void doneExplore()
  {
    Link l = explorePtr;
    explorePtr.x = explore[l.x][l.y].x;
    explorePtr.y = explore[l.x][l.y].y;
    explore[l.x][l.y].x = Nil;
    explore[l.x][l.y].y = Nil;
  }

  bool isQueueValid()
  {
    return !queue[queueNr].empty() && (exploreState == ES_OK || queueNr == 0);
  }

  void loop();

  template<class T>
  bool checkTheCell()
  {
    pushState();
    Cell& c = exploreCell();
    c.m = T_Empty;
    neighborhood<T>(explorePtr.x, explorePtr.y);
    loop();

    if (exploreState != ES_OK)
    {
      popState();
      Cell& c = exploreCell();
      c.m = T_Empty;
      --unknowns;
      return true;
    }
    else
    {
      popState();
      return false;
    }
  }

  void loop()
  {
    while (isQueueValid())
    {
      while (isQueueValid())
	dequeue();

      queue[queueNr].clear();

      if (queueNr == 0)
	while (nextExplore())
	{
	  if (checkTheCell<ActionDecrement>()) // Check for mine in this cell
	  { // There is definitely NO mine here
	    neighborhood<ActionIncrement>(explorePtr.x, explorePtr.y);
	    doneExplore();
	    break;
	  }

	  if (checkTheCell<ActionIncrement>()) // Check for NO mine in this cell
	  { // There is definitely a mine here
	    neutralize(explorePtr.x, explorePtr.y);
	    neighborhood<ActionDecrement>(explorePtr.x, explorePtr.y);
	    doneExplore();
	    break;
	  }

	  doneExplore();
	}
    }
  }

  bool look(unsigned x, unsigned y)
  {
    if (field[queueNr][x][y].m != T_Unknown)
      return false;

    char z = survey(x, y);
    if (z == 'M')
    {
      neutralize(x, y);
      neighborhood<ActionDecrement>(x, y);
      field[queueNr][x][y].m = T_Empty;
    }
    else
    {
      if (z == '0')
      {
	neighborhood<ActionCleanup>(x, y);
	touch(x, y);
      }

      field[queueNr][x][y].m = down(z);
      neighborhood<ActionIncrement>(x, y);
      neighborCnt(x, y);
    }

    --unknowns;
    loop();
    return true;
  }

  struct ActionBlind
  {
    void operator () (unsigned x, unsigned y)
    {
      neutralize(x, y);
      field[queueNr][x][y].m = T_Empty;
      --unknowns;
    }
  };

  bool doBlocks()
  {
    blk = n / 3;

    for (unsigned i = 0; i < blk; ++i)
      for (unsigned j = 0; j < blk; ++j)
      {
	unsigned x = 3 * i + 2;
	unsigned y = 3 * j + 2;

	char z = survey(x, y);
	if (z == 'M')
	{
	  neutralize(x, y);
	  z = survey(x, y);
	}

	switch (z)
	{
	case '0':
	  neighborhood<ActionCleanup>(x, y);
	  break;

	case '8':
	  neighborhood<ActionNeutralize>(x, y);
	  z = '0';
	  break;

	default:
	  break; // leave T_Unknown
	}

	field[queueNr][x][y].m = down(z);
	--unknowns;
	++blockMines[down(z)];

	if (unknowns <= k || m == 0)
	  return true;
      }

    blockBlind = 7;
    unsigned sum = 0;
    for (; blockBlind > 0; --blockBlind)
    {
      sum += blockMines[blockBlind] * (8 - blockBlind);
      if (sum > k - m)
	break;
    }
    ++blockBlind;

    queue[0].clear();
    return false;
  }

  bool doBlind(unsigned d)
  {
    for (unsigned i = 0; i < blk; ++i)
      for (unsigned j = 0; j < blk; ++j)
      {
	if (k - m < 8)
	  return false;

	unsigned x = 3 * i + 2;
	unsigned y = 3 * j + 2;

	unsigned char cntHere = field[queueNr][x][y].m;
        if (cntHere < d)
	  continue;

	neighborhood<ActionBlind>(x, y);
	field[queueNr][x][y].m = 0;
	field[queueNr][x][y].e = 8;
	m += 8 - cntHere;

	if (unknowns <= k || m == 0)
	  return true;
      }

    return false;
  }

  bool doCheckers()
  {
    for (unsigned i = 1; i <= n; ++i)
      for (unsigned j = 1; j <= n; ++j)
	if ((i + j) & 1)
	  if (look(i, j) && (unknowns <= k || m == 0))
	    return true;
    return false;
  }

  bool doRest(unsigned p = 1)
  {
    unsigned t = p;

    for (unsigned i = 1; i <= n; ++i)
      for (unsigned j = 1; j <= n; ++j)
 	if (--t == 0)
	{
	  t = p;
	  if (look(i, j) && (unknowns <= k || m == 0))
	    return true;
	}

    return false;
  }

  void doAllKnown()
  {
    if (m)
      for (unsigned i = 1; i <= n; ++i)
	for (unsigned j = 1; j <= n; ++j)
	  if (field[queueNr][i][j].m == T_Unknown)
	    neutralize(i, j);
  }

  void solveWithBlocks()
  {
    if (doBlocks() ||
	doBlind(blockBlind) ||
	doCheckers() ||
	doRest())
      doAllKnown();
  }

  void solveWithNoBlocks()
  {
    if (doCheckers() ||
	doRest())
      doAllKnown();
  }

  void solve()
  {
    init();

    if (k == m && m / double(n*n) > 0.16)
      solveWithNoBlocks();
    else
      solveWithBlocks();
  }
}

int main()
{
  std::cin >> n >> m >> k;
  solve();
  std::cout << "Done" << std::endl;
  return 0;
}