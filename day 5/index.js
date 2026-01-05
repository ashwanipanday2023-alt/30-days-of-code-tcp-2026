let board = ["", "", "", "", "", "", "", "", ""];
let currentPlayer = "X";
let gameActive = true;

const cells = document.querySelectorAll(".cell");
const resetBtn = document.getElementById("resetBtn");

const winPatterns = [
  [0,1,2],[3,4,5],[6,7,8],
  [0,3,6],[1,4,7],[2,5,8],
  [0,4,8],[2,4,6]
];

// SVG templates
function createX() {
  return `
    <svg class="x" viewBox="0 0 100 100">
      <line x1="20" y1="20" x2="80" y2="80" />
      <line x1="80" y1="20" x2="20" y2="80" />
    </svg>`;
}

function createO() {
  return `
    <svg class="o" viewBox="0 0 100 100">
      <circle cx="50" cy="50" r="35" />
    </svg>`;
}

// Cell click
cells.forEach(cell => {
  cell.addEventListener("click", () => {
    const index = cell.dataset.index;

    if (board[index] !== "" || !gameActive) return;

    board[index] = currentPlayer;
    cell.innerHTML = currentPlayer === "X" ? createX() : createO();

    checkResult();
    currentPlayer = currentPlayer === "X" ? "O" : "X";
  });
});

// Check win/draw
function checkResult() {
  for (let pattern of winPatterns) {
    const [a, b, c] = pattern;

    if (
      board[a] &&
      board[a] === board[b] &&
      board[a] === board[c]
    ) {
      gameActive = false;
      document.body.classList.add("win");
      setTimeout(() => alert(`Player ${board[a]} wins 🎉`), 200);
      return;
    }
  }

  if (!board.includes("")) {
    gameActive = false;
    alert("It's a Draw 🤝");
  }
}

// Reset game
resetBtn.addEventListener("click", () => {
  board.fill("");
  cells.forEach(cell => cell.innerHTML = "");
  currentPlayer = "X";
  gameActive = true;
  document.body.classList.remove("win");
});
