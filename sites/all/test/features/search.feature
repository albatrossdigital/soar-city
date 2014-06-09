Feature: Testing sitewide search through select keywords

  Scenario: Access homepage
    Given I go to homepage
    When I fill in "edit-keys" with "\"Enoch Pratt Free Library re-opened the Herring Run Branch\""
    And I press "Search"
    Then I should see "Herring Run Branch Reopens"
