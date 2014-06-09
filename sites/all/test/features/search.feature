Feature: Testing Test Enviroment Works

  Scenario: Access homepage
    Given I go to homepage
    When I fill in "edit-keys" with "\"Free Children's Flu Shot\""
    And I press "Search"
    Then I should see "Wednesday, August 13, 2014"
