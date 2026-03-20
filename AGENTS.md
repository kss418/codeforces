# AGENTS.md

## Scope

This file applies to everything under `Codeforces/`.

## Directory Layout

- Regular contest folders use these patterns:
  - `Div.1 + Div.2/<hundreds>/<round>/`
  - `Div.2/<hundreds>/<round>/`
  - `Div.3/<hundreds>/<round>/`
  - `Div.4/<hundreds>/<round>/`
- Educational rounds use the pattern `Edu/<hundreds>/Edu<round>/`.
- Special rounds can live under `Div.1 + Div.2/Others/<Round Name>/`.
- The leaf folder name is the repository key for that contest folder.
- The README link must use the actual Codeforces contest URL, even when the leaf folder name is not the contest ID.
- `Images/` is not a contest folder and should be ignored during contest-folder sweeps.

## Source File Placement

- Keep solution files inside the matching contest folder.
- Use the filename format `<Letter>.cpp`.
- For split problems, use repository-style names such as `E1.cpp`, `E2.cpp`, `G1.cpp`, or `G2.cpp`.
- If new Codeforces solution files are sitting in the workspace root, move them into the correct contest folder under this tree.

## README Format

- Each contest folder should have a `README.md`.
- The first line must be the contest URL, for example:

```md
# https://codeforces.com/contest/2062
```

- Use one blank line between problem lines.
- Use this line format:

```md
A / Rating : $800$ / Greedy
B / Rating : $900$ / Math
E1 / Rating : $2000$ / Lazy_Propagation, ETT, Greedy
```

- If a rating is unknown, use `$-$`.
- Use plain rating values only:

```md
$800$
$-$
```

- Do not use color markup such as `\color{...}` in ratings.
- By default, list only the problems that actually have source files in that contest folder, unless the user asks for placeholders for unsolved problems.

## Rating Source Rules

- Use official Codeforces API data first when filling or refreshing ratings.
- Primary endpoints:
  - `https://codeforces.com/api/problemset.problems`
  - `https://codeforces.com/api/contest.list`
- Use `contest.list` to verify the real contest ID and contest name.
- Use `problemset.problems` to fetch the problem rating.
- Match ratings by `(contestId, index)`.
- For README labels like `E-1`, `E-2`, `G-1`, or `G-2`, remove the hyphen when matching against the API:
  - `E-1` -> `E1`
  - `G-1` -> `G1`
- If the official API does not provide a `rating` field for that problem yet, keep `$-$`.
- For simultaneous `Div. 1` / `Div. 2` rounds, `problemset.problems` may lag or omit some merged-division ratings.
- In that case, verify the rating from the official Codeforces problem page for that exact problem before leaving `$-$`.
- Do not infer or guess ratings from tags, contest type, or third-party color markup.
- If a README has a wrong contest URL header, fix the header to the actual contest ID before applying ratings.
- This matters especially for named rounds such as `Educational`, `Global`, `Hello`, `Good Bye`, `Pinely`, or `EPIC`, where the folder key may not equal the contest ID.

## Image Rules

- Shared Codeforces images live directly under `Images/`.
- Do not create or reuse nested image folders under `Images/`.
- If a contest README includes an image, keep it after the problem list.
- Use a single image only.
- Use this image line format:

```md
![My Image](https://github.com/kss418/Codeforces/blob/main/Images/994.png)
```

- When following existing repository style, the image filename should usually match the contest folder key, such as `994.png`.

## Tagging Rules

- Tags should reflect the actual solution code, not just the official problem category.
- Prefer repository-style spellings already used often in this tree.
- Common normalized tags include:
  - `Implementation`
  - `Case_Work`
  - `Math`
  - `Strings`
  - `Greedy`
  - `Prefix_Sum`
  - `BFS`
  - `DFS`
  - `DP`
  - `Combinatorics`
  - `Segment_Tree`
  - `Lazy_Propagation`
  - `Binary_Search`
  - `Number_Theory`
  - `Priority_Queue`
  - `Sorting`
  - `Graphs`
  - `Trees`
  - `Constructive`
  - `Ad_Hoc`

- Prefer these normalized names over inconsistent variants:
  - `Bit_Mask` instead of `Bitmasks`
  - `Strings` instead of `String`
  - `Trees` instead of `Tree`
  - `Tree_Map` instead of `Tree_map`
  - `Disjoint_Set` instead of `DSU`
  - `Disjoint_Set` instead of `Union_Find`

## New Contest Workflow

1. Compute the target contest folder from the contest type and round.
2. Create the folder if it does not exist.
3. Move the solved source files into it.
4. Create or update `README.md`.
5. Use `$-$` for ratings that are still unknown.
6. Fill tags based on the actual code.
7. Verify that:
   - filenames are correct
   - the README link matches the actual contest URL
   - the README uses plain ratings with no color markup

## Existing Contest Cleanup

When normalizing older contests in this tree:

1. Check whether the README link matches the actual contest URL.
2. Normalize ratings to `$number$` or `$-$`.
3. Remove rating color markup.
4. Update tags only when the current tag is clearly inconsistent with the solution code or repository style.
5. Preserve everything else unless the user asks for broader cleanup.
