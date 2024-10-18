CarSystem - Contribution Standards

The purpose of this document is to **establish the contribution standards** for _contributors_ of the `CarSystem` project as well as ensuring that individual _contributions_ are well-formed and fulfill the relevant criteria.

To ensure correctness and traceability in project contributions, **all contributors** are expected to have **read and understood the content of this document**.

## Table of Contents


- [Contributor Guidelines](#contributor-guidelines)
  - [Creating Issues](#creating-issues)
  - [Writing Commit Messages](#writing-commit-messages)
  - [Creating Branches](#creating-branches)
  - [Creating, Handling Merge Requests](#creating-handling-merge-requests)
  - [Closing Issues](#closing-issues)


## Contributor Guidelines

### Creating Issues

- **Issue titles & descriptions** shall use the [imperative mood](https://en.wikipedia.org/wiki/Imperative_mood), such that it forms a *command or request*.
- Each issue must have the appropriate **labels** attached, such as *'feature'* for a new feature or *'bug'* for a bug in the code.
- **Sprint information** label (e.g. *'Sprint:2'*) should almost always be provided;
  - the **exceptions** being bug fixes or updates to the documentation, in which case such a label can be omitted.
- An appropriate **due date** should be added to the issue with respect to the Sprint's deadline.
- When creating an issue that corresponds to a **feature request**, it is important to adhere to the provided **issue template**:
  - The issue description should include a **user story** or **SRS-format** requirement description. 
    - This shall correlate with, and link to, the corresponding requirement listed in the project's `wiki` section. <!-- TODO: add link -->
  - Alternatively, if more feasible, a textual natural language description can be used.
  - The author must also provide **acceptance criteria** that outline the specific implementation requirements that must be met for the feature to be considered complete.
- For **bug fixes or documentation enhancements**, a textual natural language description is sufficient to describe the issue.
> Once an issue has been assigned, the assignee is encouraged to continuously **update the acceptance criteria check boxes** based on the committed implementations to track and communicate what work remains to be done.

### Writing Commit Messages

- Commit messages shall be written in the [imperative mood](https://en.wikipedia.org/wiki/Imperative_mood) and contributors must make their **best efforts** to follow English grammar rules and ortography.
- The commit **title** shall include the corresponding **issue number** via the `#<n>` syntax (followed by a whitespace) to ensure traceability.
  - The commit title shall not end with a period. 
- It is required to provide a **description** for each commit. It should cover the **rationale** for the changes and briefly describe the **approach** taken to implement them.
- In cases where **multiple individuals** work on a commit, the *"Co-authors: ..."* convention should be utilized to acknowledge their contribution.
> **IMPORTANT: do <u>not</u> push commits directly to the main branch, and <u>never</u> any code changes.** The only exceptions are for certain documentational changes such as in the `README.md` file.

### Creating Branches
- In adherence to the feature-branch workflow, **a distinct branch** shall be created for **every issue**. It is important to ensure that the branch is created from the corresponding issue. The **branch name** should be **succinct**, while also bearing **resemblance** to the content of the issue.
- Any additions or changes related to the implementation of a certain [issue](#creating-issues) must first be made using the correlating branch, and later on *merged* with the `main branch` via a [merge-request](#creating-handling-merge-requests).
- Branch names must also include the related **issue number** as prefix. 
> **Example**: "\#1-add-contributing-md"

### Creating, Handling Merge Requests

- A merge request must have an **assignee** (i.e., the assignee of the corresponding issue) and a **reviewer** (a different team member).
- The merge request shall retain the **labels** from the issue, including the `needs-review` label, upon creation.
- As a **reviewer**, the duties are to:
  - **ensure** that the code meets **acceptable quality** standards and fulfills the desired feature request,
  - **provide feedback** and/or **code reviews** to improve the feature if necessary,
  - ***approve*** the merge request if they believe it is suitable for the system's development.
- Once the merge request is approved, the `needs-review` label shall be removed.
> **Only after these steps have been completed can the assignee *merge* the merge request.**

### Closing Issues

- Feature requests that are *temporarily* moved outside of the project scope can have the `out-of-scope` label attached - but **kept open** - to indicate that it is likely to be re-evaluated at a future point. 
- In the event that a particular feature is deemed unfeasible or otherwise *descoped*, it may be **closed** with the addition of the `deprecated` label. If necessary, the feature can be revisited and subsequently reopened.
